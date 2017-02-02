#include <cdrawcamera.h>

CDrawCamera::CDrawCamera()
{

}

/**
 * @brief CDrawCamera::DecodeLogitechImageMsg
 * @param msg
 */
void CDrawCamera::DecodeLogitechImageMsg(const LOGITECH_IMAGE *msg)
{
    m_mtuLogitechImage.lock();
//    if (-1 == m_msgLogitechImage.decode(recvBuf->data, 0, recvBuf->data_size))
//    {
//        PrintErrorInfo("cannot decode LOGITECH_IMAGE", __FILE__, __FUNCTION__, __LINE__);
//    }
    memcpy(&m_msgLogitechImage,msg,sizeof(LOGITECH_IMAGE));
    m_mtuLogitechImage.unlock();
}

/**
 * @brief CDrawCamera::GLDrawLogitechImage
 * @param width
 * @param height
 */
void CDrawCamera::GLDrawLogitechImage(int &width, int &height)
{
    m_mtuLogitechImage.lock();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_msgLogitechImage.nWidth, m_msgLogitechImage.nHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_msgLogitechImage.gbImageData);
    width = m_msgLogitechImage.nWidth;
    height = m_msgLogitechImage.nHeight;
    m_mtuLogitechImage.unlock();
}
