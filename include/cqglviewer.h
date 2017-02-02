#ifndef CQGLVIEWER_H
#define CQGLVIEWER_H

#include <lib3ds/file.h>
#include <lib3ds/node.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>
#include <QGLViewer/qglviewer.h>
#include <QGLViewer/manipulatedCameraFrame.h>
#include <QFileDialog>

#include "clcmsubscriber.h"


enum CURRENT_CAMERA_VIEW
{
    CCV_WORLD,
    CCV_VEHICLE,
    CCV_VELODYNE,
    CCV_MOBILEYE,
    CCV_IBEO
};
//display control struct, the struct element is set by the toogle button; set the default value to true to draw the corresponding data on the opengl by default;
struct DISPLAY_CONTROL
{
    //raw sensor info
    //====================================
    bool bRawVelodyneIntensity;
    bool bRawVelodyneHeight;
    bool bRawImage;
    bool bLogitechImage;
    bool bRawMobileyeLanes;
    bool bRawMobileyeObjects;
    bool bRawMobileyeHPP;
    bool bRawMobileyeTFLMain;
    bool bRawMobileyeTFLFisheye;
    bool bRawVCU550;
    bool bRawINS;
    
    bool bRawFrontMWR;
    bool bFilteredFrontMWRObjects;
    bool bFilteredBackMWRObjects;
    bool bSelectedFrontMWRObjects;
    bool bSelectedBackMWRObjects;
    bool bRawLeftMWR;
    bool bRawRightMWR;

    bool bRawIBEOObjects;
    bool bRawIBEOPoints;

    bool bRawFrontLux;
    bool bRawLeftLux;
    bool bRawBackLux;
    bool bRawRightLux;

    //preprocessed sensor info
    //====================================
    bool bFilteredIBEOObjects;
    bool bVelodyneGroundEstimation;
    bool bVelodyneObjectClusters;
    bool bVelodyneObjectConvexHulls;
    bool bVelodyneObjectCorrelations;
    bool bVelodyneTrackedObjects;
    bool bVelodyneGridMapLabel;
    bool bVelodyne720Points;
    bool bFilteredMobileyeObjects;

    //fusion info;
    //====================================
    bool bVirtualLanes;
    bool bOctObstacles;
    bool bIBEOSelectedObjects;
    bool bTrackObjects;
    bool bPerceptionLanes;
    bool bPerceptionObjects;
    bool bPerceptionTFLs;

    //decision info;
    //====================================
    bool bPlannedTrajectory;
    bool bFittedTrajectory;

    bool bVehicleModel;
    bool bCoordinates;
    bool bSquareGrids;
    bool bRadicalGrids;

    CURRENT_CAMERA_VIEW stCurrentCameraView;

    DISPLAY_CONTROL()
    {
        bRawVelodyneIntensity = false;
        bRawVelodyneHeight = false;
        bRawImage = true;
        bLogitechImage = true;
        bRawMobileyeLanes = false;
        bRawMobileyeObjects = false;
        bRawMobileyeHPP = false;
        bRawMobileyeTFLMain = false;
        bRawMobileyeTFLFisheye = false;
        bRawINS = true;
        bRawVCU550 = true;
        bRawIBEOObjects = false;
        bRawIBEOPoints = false;
        
        bRawFrontMWR = false;
        bFilteredFrontMWRObjects = false;
        bFilteredBackMWRObjects = false;
        bSelectedFrontMWRObjects = false;
        bSelectedBackMWRObjects = false;
        bRawLeftMWR = false;
        bRawRightMWR = false;

        bRawFrontLux = false;
        bRawLeftLux = false;
        bRawBackLux = false;
        bRawRightLux = false;

        bFilteredIBEOObjects = true;
        bVelodyneGroundEstimation = false;
        bVelodyneObjectClusters = false;
        bVelodyneObjectConvexHulls = false;
        bVelodyneObjectCorrelations = false;
        bVelodyneTrackedObjects = false;
        bVelodyneGridMapLabel = false;
        bVelodyne720Points = false;
        bOctObstacles = false;
        bFilteredMobileyeObjects=true;

        bVirtualLanes = false;
        bPerceptionLanes = true;
        bIBEOSelectedObjects = false;
        bTrackObjects = false;
        bPerceptionObjects = false;

        bPlannedTrajectory = false;
        bFittedTrajectory = false;

        bVehicleModel = true;
        bCoordinates = true;
        bSquareGrids = false;
        bRadicalGrids = false;

        bPerceptionTFLs = false;
    }
};

class CQGLViewer:public QGLViewer
{
public:
    CQGLViewer(QWidget* parent);
    DISPLAY_CONTROL m_stDisplayControl;
    void draw();

private:
    const bool Load3dsModel();
    void Render3dsNode(Lib3dsNode* node);
    void InitializeScene();
    const bool LoadImage();

protected:
//    virtual void draw();
    virtual QString helpString() const;
    virtual void init();

private:
    Lib3dsFile* m_p3dsFile;
    char* m_p3dsCameraName;
    QImage glImg;
    QFont m_qFont2DText;
    int m_nScreenTextX;
    int m_nScreenTextY;

    void DrawRawINS();
    void DrawImage();


};

#endif // CQGLVIEWER_H
