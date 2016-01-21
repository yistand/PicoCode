#!/bin/tcsh

echo "[i] Remove any existing libs"
rm -v *.so

setenv SAVEDIR ${PWD}
cd ..

setenv JETPICODIR "${PWD}/eventStructure"

echo "[i] Recompile event structure"
cd ${JETPICODIR}
#make clean && make
make
cd ${SAVEDIR}
cd ..

setenv CXXFLAGSNEW "-pipe -fPIC -Wall -Woverloaded-virtual -ansi -Wno-long-long -pthread -I${JETPICODIR} -m32"
LDFLAGS       += -m32

echo "[i] Changing CXXFLAGS to:"${CXXFLAGSNEW}
setenv COMPILEDIR /tmp/picojetcompile${USER}
echo "[i] Running cons for JetPicoMaker in a temp directory "${COMPILEDIR}

rm ${COMPILEDIR} -rf
mkdir -p ${COMPILEDIR}

cd ${COMPILEDIR}
mkdir StRoot
cp -rv ${SAVEDIR} ${COMPILEDIR}/StRoot/

cons CXXFLAGS="${CXXFLAGSNEW}" +JetPicoMaker

echo "[i] Copying libraries to the local directory"
find .*/lib -name "*JetPicoMaker.so" -exec cp -v {} ${SAVEDIR} \;
#find .*/lib -name "*.so" -exec ln -s {} ${SAVEDIR}/{} \;
cp -v ${JETPICODIR}/*.so ${SAVEDIR}
cp -v ${SAVEDIR}/*.so ${SAVEDIR}/../../

rm ${COMPILEDIR} -rf

cd ${SAVEDIR}
ls *.so -ltr

echo "[i] Run a zero level test"
root4star LoadLibs.C -q -b

