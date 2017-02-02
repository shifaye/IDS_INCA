#!/usr/bin/env python3
import os
import shutil

#clear folder
def ClearFolder(path):
    dirs=os.listdir(path)
    for dir in dirs:
        if dir=='.gitkeep':
            continue
        else:
            full_path = path+'/'+dir
            if os.path.isfile(full_path):
                os.remove(full_path)
            else:
                shutil.rmtree(full_path)
    return

#clear sub folders
def ClearSubFolders(path):
    #print(path)
    dirs=os.listdir(path)
    #print(dirs)
    for dir in dirs:
        full_path = path+'/'+dir
        if os.path.isfile(full_path):
            continue
        else:
            ClearFolder(full_path)
        


#create .gitkeep file to save the directory
def AddGitKeep(full_path):
    filename=full_path+'/.gitkeep'
    if not os.path.exists(filename):
        gitkeep = open(filename, 'w')
        gitkeep.close()
    return

def CreateDefaultFolders():
    path=os.getcwd()
    default_folders=['bin', 'build', 'doc', 'include', 'lib', 'doc', 'src', 'ui']
    for folder in default_folders:
        folder = path+'/'+folder
        if not os.path.exists(folder):
            os.makedirs(folder)    
    return


CreateDefaultFolders()
dirs=os.listdir()
#print('dirs: %s' % dirs)
path = os.getcwd()
#print('path: %s' % path)

for dir in dirs:
    full_path = path+'/'+dir
    #print('full_path:%s'%full_path)
    if os.path.isfile(full_path):
        filename,ext = os.path.splitext(dir)
        #print("filename:%s,ext:%s"%(filename,ext))
        if dir=="CMakeCache.txt" or dir=="cmake_install.cmake" or dir=="CMakeLists.txt.user" or dir=="CTestTestfile.cmake" or dir=="Makefile":
            os.remove(full_path)
        elif ext==".cbp" or ext==".cpp" or ext==".kdev4":
            os.remove(full_path)
    else:
        if dir=="test_results" or dir=="catkin" or dir=="catkin_generated" or dir=="CMakeFiles" or dir=="devel" or dir=="gtest" or dir=="__" or dir==".kdev4":
            shutil.rmtree(full_path)
        else:
            AddGitKeep(full_path)
            if dir=="build":
                #ClearSubFolders(full_path)
                ClearFolder(dir)
        #print("directory:%s"%(dir))
