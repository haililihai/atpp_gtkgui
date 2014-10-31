#! /bin/bash

WD=$1
shift
DATA_DIR=$1
shift
PREFIX=$1
shift
PART=$1
shift
SUB_LIST=$1
shift
N_SAMPLES=$1
shift
DIS_COR=$1
shift
LEN_STEP=$1
shift
N_STEPS=$1
shift
CUR_THRES=$1
shift
LEFT=$1
shift
RIGHT=$1

# create a directory to check the status
if [ -d ${WD}/qsub_jobdone ]
then
	rm -rf ${WD}/qsub_jobdone
	mkdir -p ${WD}/qsub_jobdone
else
	mkdir -p ${WD}/qsub_jobdone
fi

if [ "${DIS_COR}" == "1" ];then
	DIS_COR=--pd
else
	DIS_COR= 
fi

for sub in $(cat ${SUB_LIST})
do
	# single voxel probtrackx
if [ "${LEFT}" == "1" ]; then
	job_id=$(fsl_sub -p 1024 probtrackx --mode=simple --seedref=${DATA_DIR}/${sub}/DTI.bedpostX/nodif_brain_mask -o ${PART}_L -x ${WD}/${sub}/${PREFIX}_${sub}_${PART}_L_coord.txt -l ${DIS_COR} -c ${CUR_THRES} -S ${N_STEPS} --steplength=${LEN_STEP} -P ${N_SAMPLES} --forcedir --opd -s ${DATA_DIR}/${sub}/DTI.bedpostX/merged -m ${DATA_DIR}/${sub}/DTI.bedpostX/nodif_brain_mask --dir=${WD}/${sub}/${PREFIX}_${sub}_${PART}_L_probtrackx &)
	echo "${sub}_L probtrackx is running...! job_ID is ${job_id}"
	mute=$(fsl_sub -j ${job_id} -N running... touch ${WD}/qsub_jobdone/${sub}_L.jobdone)
fi

if [ "${RIGHT}" == "1" ]; then
	job_id=$(fsl_sub -p 1024 probtrackx --mode=simple --seedref=${DATA_DIR}/${sub}/DTI.bedpostX/nodif_brain_mask -o ${PART}_R -x ${WD}/${sub}/${PREFIX}_${sub}_${PART}_R_coord.txt -l ${DIS_COR} -c ${CUR_THRES} -S ${N_STEPS} --steplength=${LEN_STEP} -P ${N_SAMPLES} --forcedir --opd -s ${DATA_DIR}/${sub}/DTI.bedpostX/merged -m ${DATA_DIR}/${sub}/DTI.bedpostX/nodif_brain_mask --dir=${WD}/${sub}/${PREFIX}_${sub}_${PART}_R_probtrackx &)
	echo "${sub}_R probtrackx is running...! job_ID is ${job_id}"
	mute=$(fsl_sub -j ${job_id} -N running... touch ${WD}/qsub_jobdone/${sub}_R.jobdone)
fi
	
done


# check whether the tasks are finished or not
N=$(cat ${SUB_LIST}|wc -l)
if [ "${LEFT}" == "1" -a "${RIGHT}" == "0" ]
then
	while [ "$(ls ${WD}/qsub_jobdone|wc -l)" != "${N}"  ]
	do
		sleep 30s
	done	
fi

if [ "${LEFT}" == "0" -a "${RIGHT}" == "1" ]
then
	while [ "$(ls ${WD}/qsub_jobdone|wc -l)" != "${N}"  ]
	do
		sleep 30s
	done	
fi

if [ "${LEFT}" == "1" -a "${RIGHT}" == "1" ]
then
	while [ "$(ls ${WD}/qsub_jobdone|wc -l)" != "$((${N}*2))"  ]
	do
		sleep 30s
	done	
fi

echo "=== Finally Probtrackx All Done!! ==="
