#! /bin/bash

# Automatic Tractography-based Parcellation Pipeline (ATPP) with GUI
#
# ---- Single ROI oriented brain parcellation
# ---- Automatic parallel computing
# ---- Modular and flexible structure
# ---- Simple and easy-to-use settings
#
# Usage: sh ATPP.sh batch_list.txt
# 2014.7.13 V0.9
# Hai Li (hai.li@nlpr.ia.ac.cn)


#==============================================================================
# Prerequisites:
# 1) Tools: FSL (with FDT toolbox), SGE and MATLAB (with SPM8 and NIfTI toolbox)
# 2) Data files:
#    > T1 image for each subject
#	 > b0 image for each subject
# 	 > images preprocessed by FSL(BedpostX) for each subject
# 3) Directory structure:
#	  Working_dir
#     |-- sub1
#     |   |-- T1_sub1.nii
#     |   |-- b0_sub1.nii
#     |-- sub2
#     |-- ...
#     |-- subN
#     |-- ROI
#     |   |-- ROI_L.nii
#     |   `-- ROI_R.nii
#     `-- log 
#==============================================================================

#===============================================================================
# Global configuration file
# Before running the pipeline, you NEED to modify parameters in the file.
#===============================================================================
source ./atpp_gui_config.sh

#====================================================================================
# batch processing parameter list
# DO NOT FORGET TO EDIT batch_list.txt itself to include the appropriate parameters
#====================================================================================
# batch_list.txt contains the following 7 parameters in order in each line:
# - Data directory , e.g. /DATA/233/hli/Data/chengdu
# - Prefix of data , e.g. CD
# - List of subjects , e.g. /DATA/233/hli/Data/chengdu/sub_CD.txt
# - Brain region name , e.g. Amyg
# - working directory , e.g. /DATA/233/hli/Amyg
# - Maximum cluster number , e.g. 6
# - Cluster number , e.g. 3
#test -e $1 && BATCH_LIST=$1 || BATCH_LIST=${PIPELINE}/batch_list.txt

#===============================================================================
# environment variables that can be modified if necessary
#===============================================================================
LOCAL_soft=/mnt/software
alias matlab='${LOCAL_soft}/matlab/bin/matlab'
FSLDIR=${LOCAL_soft}/fsl5.0
. ${FSLDIR}/etc/fslconf/fsl.sh
PATH=${FSLDIR}/bin:${PATH}
export FSLDIR PATH
export LD_LIBRARY_PATH=/lib:/lib64:/usr/lib:${LOCAL_soft}/lib:${LOCAL_soft}/fsl/
export PATH=$PATH:/usr/lib/x86_64-linux-gnu/
export PATH=$PATH:$LOCAL_soft/matlab/bin

#===============================================================================
#----------------------------START OF SCRIPT------------------------------------
#----------NO EDITING BELOW UNLESS YOU KNOW WHAT YOU ARE DOING------------------
#===============================================================================

#while read line
#do

# 1. cut specific parameters from batch_list
#DATA_DIR=$( echo $line | cut -d ' ' -f1 )
#PREFIX=$( echo $line | cut -d ' ' -f2 )
#SUB_LIST=$( echo $line | cut -d ' ' -f3 )
#PART=$( echo $line | cut -d ' ' -f4 )
#WD=$( echo $line | cut -d ' ' -f5 )
#MAX_CL_NUM=$( echo $line | cut -d ' ' -f6 )
#CL_NUM=$( echo $line | cut -d ' ' -f7 )



# 2. distribute a task to the most available host
#IP=`qhost | awk 'NR>4{print $4/$3,$1}' | sort -n | awk 'NR==1{print $2}'`

# 3. do the processing
mkdir -p ${WD}/log
#echo "============================================================="
#echo "=============== ATPP running... -- ${PART}@${IP} ==============="
${PIPELINE}/pipeline.sh ${PIPELINE} ${WD} ${DATA_DIR} ${PREFIX} ${PART} ${SUB_LIST} ${MAX_CL_NUM} ${CL_NUM} >${WD}/log/ATPP_log_$(date +%m-%d_%H-%M).txt 2>&1 &
stopid=$(pgrep -P $$)
echo ${stopid}
#echo "==== Processing info @ ${WD}/log/ATPP_log_$(date +%m-%d_%H-%M).txt ====" 
#sleep 15s # waiting for a proper host

#done < ${BATCH_LIST}
