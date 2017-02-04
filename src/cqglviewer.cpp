#include "cqglviewer.h"

extern CLCMSubscriber* g_pLcmSubscriber;
CQGLViewer::CQGLViewer ( QWidget* parent ) :
    QGLViewer ( parent ),
    m_qFont2DText ( "Ubuntu", 12 ),
    m_nScreenTextX ( 10 ),
    m_nScreenTextY ( 35 )
{
    startAnimation();
    draw();
}

/**@brief draw ins text on the opengl;
 *
 * draw ins text on the opengl, the ins including spatial fog and inertial;
 *@return void;
 *@note
 *@todo the inertial should be added;
 */
void CQGLViewer::DrawRawINS()
{

}

/**@brief draw image on the opengl;
 *
 * draw image on the opengl;
 *@return void;
 *@note the image size could be adjusted by the variable ratio;
 */
void CQGLViewer::DrawImage()
{
    //display image, method 2;
    if ( true )
    {
        glPushMatrix();
        int nImgWidth = 0, nImgHeight = 0;
        g_pLcmSubscriber->m_pLcmHandler->m_stCameraDrawer.GLDrawLogitechImage(nImgWidth, nImgHeight);

        float ratio = 0.85;
        int nWidth = ratio * nImgWidth;
        int nHeight = ratio * nImgHeight;

        glEnable(GL_TEXTURE_2D);
        glColor3ub(255, 255, 255);
        startScreenCoordinatesSystem(true);
        glNormal3f(0.0, 0.0, 1.0);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);
        glVertex2f(0.0f, 0.0f);
        glTexCoord2f(1.0, 1.0);
        glVertex2f(nWidth, 0.0f);
        glTexCoord2f(1.0, 0.0);
        glVertex2f(nWidth, nHeight);
        glTexCoord2f(0.0, 0.0);
        glVertex2f(0.0f, nHeight);
        glEnd();

        stopScreenCoordinatesSystem();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}


/**@brief opengl draw function;
 *
 * opengl main draw function;
 *@return void;
 *@note
 */
void CQGLViewer::draw()
{
    //@todo test how to pause display;
    //    if(m_stDisplayControl.bPauseDisplay)
    //    {
    //        return;
    //    }

    m_nScreenTextX = 10;
    m_nScreenTextY = 35;

    double T1 = GetGlobalTimeStampInSec();

    //display ins text;
    DrawRawINS();

    //display image;
    DrawImage();

}

/**@brief set help string on the help document;
 *
 * set help string on the help document;
 *@return QString: the help info;
 *@note
 */
QString CQGLViewer::helpString() const
{
    QString text ( "<h2>I n t e r f a c e</h2>" );
    text += "A GUI can be added to a QGLViewer widget using Qt's <i>Designer</i>. Signals and slots ";
    text += "can then be connected to and from the viewer.<br><br>";
    text += "You can install the QGLViewer designer plugin to make the QGLViewer appear as a ";
    text += "standard Qt widget in the Designer's widget tabs. See installation pages for details.";
    return text;
}

/**@brief QGLViewer initialize function;
 *
 * QGLViewer initialize function, this function will initialize opengl;
 *@return void;
 *@note
 */
void CQGLViewer::init()
{
    glShadeModel ( GL_SMOOTH );
    glEnable ( GL_LIGHTING );
    glEnable ( GL_LIGHT0 );
    glDisable ( GL_LIGHT1 );
    glDepthFunc ( GL_LEQUAL );
    glEnable ( GL_DEPTH_TEST );
    glDisable ( GL_COLOR_MATERIAL );
    glEnable ( GL_CULL_FACE );
    glCullFace ( GL_BACK );
    glEnable ( GL_CULL_FACE );
    glCullFace ( GL_BACK );

    //initialize scene;
    InitializeScene();

    // Enable GL textures
    glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glEnable ( GL_TEXTURE_2D );

    glBlendFunc ( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA );

    // Nice texture coordinate interpolation
    glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}


/**@brief initialize scene;
 *
 * initialize the scene, including the light and camera;
 *@return void;
 *@note
 */
void CQGLViewer::InitializeScene()
{
    this->setSceneRadius ( 10000 ); //in cm;

    if ( !m_p3dsFile )
    {
        return;
    }

//    //Lights;
//    GLfloat amb[] = {0.0f, 0.0f, 0.0f, 1.0f};
//    GLfloat dif[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    GLfloat spe[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    GLfloat pos[] = {0.0f, 0.0f, 0.0f, 1.0f};

//    int li = GL_LIGHT0;
//    for ( Lib3dsLight* l=m_p3dsFile->lights; l; l=l->next )
//    {
//        glEnable ( li );

//        glLightfv ( li, GL_AMBIENT, amb );
//        glLightfv ( li, GL_DIFFUSE, dif );
//        glLightfv ( li, GL_SPECULAR, spe );

//        pos[0] = l->position[0];
//        pos[1] = l->position[1];
//        pos[2] = l->position[2];
//        glLightfv ( li, GL_POSITION, pos );

//        if ( !l->spot_light )
//        {
//            continue;
//        }

//        pos[0] = l->spot[0] - l->position[0];
//        pos[1] = l->spot[1] - l->position[1];
//        pos[2] = l->spot[2] - l->position[2];
//        glLightfv ( li, GL_SPOT_DIRECTION, pos );
//        ++li;
//    }


//    //set camera view;
//    qglviewer::Quaternion qua;
//    qua.setAxisAngle ( qglviewer::Vec ( 0.0, 0.0, 1.0 ), -PI/2.0f );
//    camera()->setOrientation ( qua );
//    camera()->setPosition ( qglviewer::Vec ( 2000.0f, 1000.0f, 10000.0f ) );

////    //camera
//    Lib3dsNode* c = lib3ds_file_node_by_name ( m_p3dsFile, m_p3dsCameraName, LIB3DS_CAMERA_NODE );
//    Lib3dsNode* t = lib3ds_file_node_by_name ( m_p3dsFile, m_p3dsCameraName, LIB3DS_TARGET_NODE );
//    if ( !c || !t )
//    {
//        return;
//    }

//    camera()->setPosition ( qglviewer::Vec ( c->data.camera.pos ) );
//    camera()->lookAt ( qglviewer::Vec ( t->data.target.pos ) );
}




/**@brief load image to display on the opengl;
 *
 * load image to display on the opengl, only used to test;
 *@return bool: if the image is successfully initialized, return true; else, return false;
 *@note
 */
const bool CQGLViewer::LoadImage()
{
    QString name = QFileDialog::getOpenFileName ( this, "Select an image", ".", "Images (*.png *.xpm *.jpg)" );

    // In case of Cancel
    if ( name.isEmpty() )
        return false;

    QImage img ( name );

    if ( img.isNull() )
    {
        return false;
    }

    glImg = QGLWidget::convertToGLFormat ( img ); // flipped 32bit RGBA

    // Bind the img texture...
    glTexImage2D ( GL_TEXTURE_2D, 0, 4, glImg.width(), glImg.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, glImg.bits() );
    return true;
}
