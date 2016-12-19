#include "viewer.h"
#include <QGLViewer/manipulatedCameraFrame.h>

using namespace qglviewer;

Viewer::Viewer()
{

}

Viewer::Viewer(int type, QWidget* parent, const QGLWidget* shareWidget, Qt::WindowFlags flags)
    : QGLViewer(parent, shareWidget, flags)
{
    if (type < 3)
    {
      // Move camera according to viewer type (on X, Y or Z axis)
      camera()->setPosition(Vec((type==0)? 1.0 : 0.0, (type==1)? 1.0 : 0.0, (type==2)? 1.0 : 0.0));
      camera()->lookAt(sceneCenter());

      camera()->setType(Camera::ORTHOGRAPHIC);
      camera()->showEntireScene();

      // Forbid rotation
      WorldConstraint* constraint = new WorldConstraint();
      constraint->setRotationConstraintType(AxisPlaneConstraint::FORBIDDEN);
      camera()->frame()->setConstraint(constraint);
    }
}

Viewer::~Viewer()
{
    for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
        (*iter).reset();
}

void Viewer::init()
{
    particle_size       = 3;
    particle_color[0]   = 1.0f;
    particle_color[1]   = 0.0f;
    particle_color[2]   = 0.0f;
    particle_color[3]   = 0.25f;
    is_animated = false;
    setGridIsDrawn(true);
    setAxisIsDrawn(true);
    setSceneRadius(120+50+10);
    showEntireScene();
    bgcolor_default = backgroundColor();
}

void Viewer::animate()
{
    if (is_animated)
    {
        for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
            (*iter)->age_incr();
    }
}

void Viewer::draw()
{
    draw_particles(is_animated);
}

void Viewer::draw_particles(bool _is_animated)
{
    CGLA::Vec3f center(0.0f, 0.0f, 0.0f);

    for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
    {
        center = (*iter)->current_state();
        draw_sphere(center, particle_size);
        if (is_animated)
            (*iter)->age_incr();
    }
}

void Viewer::draw_sphere(CGLA::Vec3f& _vecpt, GLfloat _radius)
{
    GLint slices = 16;
    GLint stacks = 16;
    GLfloat sphrcolor[4] = {particle_color[0], particle_color[1], particle_color[2], particle_color[3]};
    GLUquadric* quad;
    quad=gluNewQuadric();
    gluQuadricNormals(quad, GL_SMOOTH);

    glPushAttrib(GL_CURRENT_BIT);
    glColor4fv(sphrcolor);

    glPushMatrix();
    glTranslatef(_vecpt[0], _vecpt[1], _vecpt[2]);
    gluSphere(quad, _radius, slices, stacks);
    glPopMatrix();

    glPopAttrib();
    gluDeleteQuadric(quad);
}

void Viewer::draw_sphere(std::vector<GLfloat>& _center, GLfloat _radius)
{
    GLint slices = 16;
    GLint stacks = 16;
    GLfloat sphrcolor[4] = {particle_color[0], particle_color[1], particle_color[2], particle_color[3]};
    GLUquadric* quad;
    quad=gluNewQuadric();
    gluQuadricNormals(quad, GL_SMOOTH);

    glPushAttrib(GL_CURRENT_BIT);
    glColor4fv(sphrcolor);
    if (_center.size()>=3)
    {
        glPushMatrix();
        glTranslatef(_center[0], _center[1], _center[2]);
        gluSphere(quad, _radius, slices, stacks);
        glPopMatrix();
    }
    glPopAttrib();
    gluDeleteQuadric(quad);
}

void Viewer::add_particle(std::unique_ptr<Particle> _particle)
{
    vec_uparticles.push_back(std::move(_particle));
}

void Viewer::keyPressEvent(QKeyEvent *e)
{
    const Qt::KeyboardModifiers modifiers = e->modifiers();
    bool handled = false;
    if ((modifiers==Qt::Key_Enter) || (e->key()==Qt::Key_Return))
    {
        is_animated = !is_animated;
    }
    else if ((modifiers==Qt::ControlModifier) && (e->key()==Qt::Key_R))
    {
        for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
            (*iter)->reset();
        updateGL();
        handled = true;
    }
    else if ((modifiers==Qt::ControlModifier) && (e->key()==Qt::Key_Right))
    {
        for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
            (*iter)->age_incr();
        updateGL();
        handled = true;
    }
    else if ((modifiers==Qt::ControlModifier) && (e->key()==Qt::Key_Left))
    {
        for (std::vector< std::unique_ptr<Particle> >::iterator iter = vec_uparticles.begin(); iter != vec_uparticles.end(); iter++)
            (*iter)->age_decr();
        updateGL();
        handled = true;
    }
    else if ((e->key()==Qt::Key_Plus)/* && (modifiers==Qt::ControlModifier)*/)
    {
        particle_size += 0.1f;
        updateGL();
        handled = true;
    }
    else if ((e->key()==Qt::Key_Minus)/* && (modifiers==Qt::ControlModifier)*/)
    {
        if (particle_size <= 0.5f)
            particle_size = 0.5f;
        else
            particle_size -= 0.1f;
        updateGL();
        handled = true;
    }
    if (!handled)
        QGLViewer::keyPressEvent(e);
}


