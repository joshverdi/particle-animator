#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "main.h"
#include "viewer.h"
#include "utils.h"
#include "ioraw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Viewer viewer;

    std::ifstream file_start("start.csv", std::ifstream::in), file_end("end.csv", std::ifstream::in);
    std::vector< std::vector<std::string> > vecstrs_start, vecstrs_end;
    std::vector< std::vector<float> > vecs_start, vecs_end;
    std::stringstream ss_start, ss_end;
    size_t pclsize;

    if (file_start)
    {
        ss_start << file_start.rdbuf();
        file_start.close();
    }

    if (file_end)
    {
        ss_end << file_end.rdbuf();
        file_end.close();
    }

    IORaw::csv_to_data(vecstrs_start, ss_start);
    IORaw::csv_to_data(vecstrs_end,   ss_end);
    vecs_start = Utils::raw_cast(vecstrs_start);
    vecs_end   = Utils::raw_cast(vecstrs_end);

    assert(vecs_start.size() == vecs_end.size());
    pclsize = vecs_start.size();
    for (int i=0; i<pclsize; i++)
        viewer.add_particle(std::unique_ptr<Particle>(new Particle(vecs_start[i], vecs_end[i])));

    viewer.setWindowTitle("RAW Particles Linear Animation");
    viewer.show();

    return a.exec();
}

