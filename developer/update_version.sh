# update_version.sh
# used to easily update the cmd20 version

#ADDME - update to parse command line args
oldVersion="0.2.0"
newVersion="0.3.0"
#FIXME - add in "-i" (after testing) to modify the files
find ../ -type f -exec sed s"/$oldVersion/$newVersion/"g {}\;
