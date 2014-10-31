
#---------Initilization----------
PIPELINE=''
WD=''
PART=''
log=''
stopid=''

switch=()
LH=0
RH=0

gtk "gtk_entry_set_text ${dir_pl} \"$(pwd)\""
gtk "gtk_entry_set_text ${dir_spm} \"/DATA/233/hli/toolbox/spm8\""
gtk "gtk_entry_set_text ${dir_nifti} \"/DATA/233/hli/toolbox/NIFTI_20130306\""
define spm_entry gtk "gtk_entry_get_text ${dir_spm}"
gtk "gtk_entry_set_text ${file_temp} \"${spm_entry}/templates/T1.nii\""
gtk "gtk_entry_set_text ${name_n_samples} \"5000\""
gtk "gtk_entry_set_text ${name_dis_cor} \"1\""
gtk "gtk_entry_set_text ${name_len_step} \"0.5\""
gtk "gtk_entry_set_text ${name_n_steps} \"2000\""
gtk "gtk_entry_set_text ${name_cur_thres} \"0.2\""
gtk "gtk_entry_set_text ${name_val_thres} \"10\""
gtk "gtk_entry_set_text ${name_down_size} \"5\""
gtk "gtk_entry_set_text ${name_method} \"Sc\""
gtk "gtk_entry_set_text ${name_vox_size} \"1\""
gtk "gtk_entry_set_text ${name_group_thres} \"0.5\""
gtk "gtk_entry_set_text ${name_mpm_thres} \"0.5\""
gtk "gtk_entry_set_text ${name_n_iter} \"100\""

define status_ready gtk "gtk_statusbar_get_context_id ${statusbar} \"ready\""
gtk "gtk_statusbar_push ${statusbar} ${status_ready} \"Ready\""

#gtk "gtk_statusbar_pop ${statusbar} ${status_ready}"

#-----------------------Callback functions---------------------------------
function on_button_dir_pl_file_set()
{
	define dir_pl_entry gtk "gtk_file_chooser_get_uri ${button_dir_pl}"
	gtk "gtk_entry_set_text ${dir_pl} \"${dir_pl_entry##file://}\""
}

function on_button_dir_ROI_file_set()
{
	define dir_ROI_entry gtk "gtk_file_chooser_get_uri ${button_dir_ROI}"
	gtk "gtk_entry_set_text ${dir_ROI} \"${dir_ROI_entry##file://}\""
}

function on_button_dir_data_file_set()
{
	define dir_data_entry gtk "gtk_file_chooser_get_uri ${button_dir_data}"
	gtk "gtk_entry_set_text ${dir_data} \"${dir_data_entry##file://}\""
}

function on_button_dir_work_file_set()
{
	define dir_work_entry gtk "gtk_file_chooser_get_uri ${button_dir_work}"
	gtk "gtk_entry_set_text ${dir_work} \"${dir_work_entry##file://}\""
}

function on_button_file_sub_file_set()
{
	define file_sub_entry gtk "gtk_file_chooser_get_filename ${button_file_sub}"
	gtk "gtk_entry_set_text ${file_sub} \"${file_sub_entry}\""
}

function on_button_dir_spm_file_set()
{
	define dir_spm_entry gtk "gtk_file_chooser_get_uri ${button_dir_spm}"
	gtk "gtk_entry_set_text ${dir_spm} \"${dir_spm_entry##file://}\""
}

function on_button_dir_nifti_file_set()
{
	define dir_nifti_entry gtk "gtk_file_chooser_get_uri ${button_dir_nifti}"
	gtk "gtk_entry_set_text ${dir_nifti} \"${dir_nifti_entry##file://}\""
}

function on_button_file_temp_file_set()
{
	define file_temp_entry gtk "gtk_file_chooser_get_filename ${button_file_temp}"
	gtk "gtk_entry_set_text ${file_temp} \"${file_temp_entry}\""
}


function on_step0_toggled()
{
	if [[ ${switch[@]/%s0/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s0/})
	else
	 	switch+=(s0)
	fi
}

function on_step1_toggled()
{
	if [[ ${switch[@]/%s1/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s1/})
	else
	 	switch+=(s1)
	fi
}

function on_step2_toggled()
{
	if [[ ${switch[@]/%s2/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s2/})
	else
	 	switch+=(s2)
	fi
}

function on_step3_toggled()
{
	if [[ ${switch[@]/%s3/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s3/})
	else
	 	switch+=(s3)
	fi
}

function on_step4_toggled()
{
	if [[ ${switch[@]/%s4/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s4/})
	else
	 	switch+=(s4)
	fi
}

function on_step5_toggled()
{
	if [[ ${switch[@]/%s5/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s5/})
	else
	 	switch+=(s5)
	fi
}

function on_step6_toggled()
{
	if [[ ${switch[@]/%s6/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s6/})
	else
	 	switch+=(s6)
	fi
}

function on_step7_toggled()
{
	if [[ ${switch[@]/%s7/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s7/})
	else
	 	switch+=(s7)
	fi
}

function on_step8_toggled()
{
	if [[ ${switch[@]/%s8/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s8/})
	else
	 	switch+=(s8)
	fi
}

function on_step9_toggled()
{
	if [[ ${switch[@]/%s9/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s9/})
	else
	 	switch+=(s9)
	fi
}

function on_step10_toggled()
{
	if [[ ${switch[@]/%s10/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s10/})
	else
	 	switch+=(s10)
	fi
}

function on_step16_toggled()
{
	if [[ ${switch[@]/%s16/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s16/})
	else
	 	switch+=(s16)
	fi
}

function on_step17_toggled()
{
	if [[ ${switch[@]/%s17/} != ${switch[@]} ]]
	then
		switch=(${switch[@]/%s17/})
	else
	 	switch+=(s17)
	fi
}

function on_left_toggled()
{
	if [[ ${LH} == 0 ]]
	then
		LH=1
	else 
		LH=0
	fi
}

function on_right_toggled()
{
	if [[ ${RH} == 0 ]]
	then
		RH=1
	else 
		RH=0
	fi
}


function on_run_clicked()
{	

	
	define res_dir_pl gtk "gtk_entry_get_text ${dir_pl}"
	[ -e ${res_dir_pl}/atpp_gui_config.sh ] && rm -f ${res_dir_pl}/atpp_gui_config.sh
	echo "PIPELINE=${res_dir_pl}" >> atpp_gui_config.sh
	PIPELINE=${res_dir_pl}

	define res_dir_ROI gtk "gtk_entry_get_text ${dir_ROI}"
	echo "ROI_DIR=${res_dir_ROI}" >> ${PIPELINE}/atpp_gui_config.sh


	define res_dir_data gtk "gtk_entry_get_text ${dir_data}"
	echo "DATA_DIR=${res_dir_data}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_dir_work gtk "gtk_entry_get_text ${dir_work}"
	echo "WD=${res_dir_work}" >> ${PIPELINE}/atpp_gui_config.sh
	WD=${res_dir_work}

	define res_dir_spm gtk "gtk_entry_get_text ${dir_spm}"
	echo "SPM=${res_dir_spm}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_dir_nifti gtk "gtk_entry_get_text ${dir_nifti}"
	echo "NIFTI=${res_dir_nifti}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_file_sub gtk "gtk_entry_get_text ${file_sub}"
	echo "SUB_LIST=${res_file_sub}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_file_temp gtk "gtk_entry_get_text ${file_temp}"
	echo "TEMPLATE=${res_file_temp}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_prefix gtk "gtk_entry_get_text ${name_prefix}"
	echo "PREFIX=${res_prefix}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_part gtk "gtk_entry_get_text ${name_part}"
	echo "PART=${res_part}" >> ${PIPELINE}/atpp_gui_config.sh
	PART=${res_part}

	define res_max_cl gtk "gtk_entry_get_text ${name_maxcl}"
	echo "MAX_CL_NUM=${res_max_cl}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_cl gtk "gtk_entry_get_text ${name_cl}"
	echo "CL_NUM=${res_cl}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_poolsize gtk "gtk_spin_button_get_value_as_int ${spin}"
	echo "POOLSIZE=${res_poolsize}" >> ${PIPELINE}/atpp_gui_config.sh

	echo "LEFT=${LH}" >> ${PIPELINE}/atpp_gui_config.sh
	echo "RIGHT=${RH}" >> ${PIPELINE}/atpp_gui_config.sh

	echo "SWITCH=(${switch[@]})" >> ${PIPELINE}/atpp_gui_config.sh

	define res_n_samples gtk "gtk_entry_get_text ${name_n_samples}"
	echo "N_SAMPLES=${res_n_samples}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_dis_cor gtk "gtk_entry_get_text ${name_dis_cor}"
	echo "DIS_COR=${res_dis_cor}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_len_step gtk "gtk_entry_get_text ${name_len_step}"
	echo "LEN_STEP=${res_len_step}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_n_steps gtk "gtk_entry_get_text ${name_n_steps}"
	echo "N_STEPS=${res_n_steps}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_cur_thres gtk "gtk_entry_get_text ${name_cur_thres}"
	echo "CUR_THRES=${res_cur_thres}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_val_thres gtk "gtk_entry_get_text ${name_val_thres}"
	echo "VAL_THRES=${res_val_thres}" >> ${PIPELINE}/atpp_gui_config.sh
	
	define res_down_size gtk "gtk_entry_get_text ${name_down_size}"
	echo "DOWN_SIZE=${res_down_size}" >> ${PIPELINE}/atpp_gui_config.sh
	
	define res_method gtk "gtk_entry_get_text ${name_method}"
	echo "METHOD=${res_method}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_vox_size gtk "gtk_entry_get_text ${name_vox_size}"
	echo "VOX_SIZE=${res_vox_size}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_group_thres gtk "gtk_entry_get_text ${name_group_thres}"
	echo "GROUP_THRES=${res_group_thres}" >> ${PIPELINE}/atpp_gui_config.sh
	
	define res_mpm_thres gtk "gtk_entry_get_text ${name_mpm_thres}"
	echo "MPM_THRES=${res_mpm_thres}" >> ${PIPELINE}/atpp_gui_config.sh

	define res_n_iter gtk "gtk_entry_get_text ${name_n_iter}"
	echo "N_ITER=${res_n_iter}" >> ${PIPELINE}/atpp_gui_config.sh

	echo "ROI_L=${WD}/ROI/${PART}_L.nii" >> ${PIPELINE}/atpp_gui_config.sh
	echo "ROI_R=${WD}/ROI/${PART}_R.nii" >> ${PIPELINE}/atpp_gui_config.sh

	stopid=$(bash ${PIPELINE}/ATPP.sh ${PIPELINE}/atpp_gui_config.sh )
	log=${WD}/log/ATPP_log_$(date +%m-%d_%H-%M).txt	

	define status_run gtk "gtk_statusbar_get_context_id ${statusbar} \"run\""
	gtk "gtk_statusbar_push ${statusbar} ${status_run} \"Running...\""
	
}

function getcpid() {
    cpids=`pgrep -P $1|xargs`
    for cpid in $cpids;
    do
        echo "$cpid"
        getcpid $cpid
    done
}

function on_stop_clicked()
{
	getcpid ${stopid}|xargs kill -9
	define status_stop gtk "gtk_statusbar_get_context_id ${statusbar} \"stop\""
	gtk "gtk_statusbar_push ${statusbar} ${status_stop} \"Stop!\""
}


function on_log_clicked()
{
	gedit ${log}
}

function on_progress_clicked()
{
	gedit ${WD}/log/progress_check.txt
}
