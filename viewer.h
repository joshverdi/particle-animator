#ifndef VIEWER_H
#define VIEWER_H

#include <QKeyEvent>
#include <QGLViewer/qglviewer.h>
#include <vector>
#include <memory>
#include "particle.h"

class Viewer : public QGLViewer
{
    std::vector< std::unique_ptr<Particle> > vec_uparticles;
    QColor  bgcolor_default;
    float   particle_color[4];
    float   particle_size;
    bool    is_animated;

public:
    Viewer();
    Viewer(int _type, QWidget* _parent=0, const QGLWidget* _shareWidget=NULL, Qt::WindowFlags _flags = 0);
    ~Viewer();
public:
    virtual void draw();
    virtual void init();
    virtual void animate();
    void draw_particles(bool _is_animated = false);
    void draw_sphere(CGLA::Vec3f& _vecpt, GLfloat _radius);
    void draw_sphere(std::vector<GLfloat>& _center, GLfloat _radius);
    void add_particle(std::unique_ptr<Particle> _particle);
protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // VIEWER_H
