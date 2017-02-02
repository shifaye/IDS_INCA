#ifndef CDRAWCAMERA_H
#define CDRAWCAMERA_H

//#include <QObject>
//#include <QStringList>
//#include <global.hpp>
#include <GL/freeglut.h>

//lcm related;
//#include <lcm/lcm-cpp.hpp>
//#include <lcm_channel.h>
#include <global.hpp>

#include <PIKE_COLOR_IMAGE.hpp>
#include <PIKE_IMAGE.hpp>
#include <LOGITECH_IMAGE.hpp>

//#include "transformlistener.h"
//#include "cdrawelement.h"
//#include "cdrawcoordinates.h"


class CDrawCamera
{
public:
    CDrawCamera();
    void DecodePikeImageMsg( const PIKE_IMAGE* msg );
    void DecodeLogitechImageMsg( const LOGITECH_IMAGE* msg);
    void GLDrawPikeImage ( int& width, int& height );
    void GLDrawLogitechImage( int& width, int& height );

private:
    boost::mutex m_mtuPikeImage;
    PIKE_IMAGE m_msgPikeImage;

    boost::mutex m_mtuLogitechImage;
    LOGITECH_IMAGE m_msgLogitechImage;

    PIKE_IMAGE GetPikeImage();
};

#endif // CDRAWCAMERA_H
