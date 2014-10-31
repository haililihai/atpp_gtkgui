until [[ "$E" -eq "window1" ]];do
    define E gtk "gtk_server_callback wait"
	[[ "$E" == "button_dir_pl_file_set" ]] && on_button_dir_pl_file_set
	[[ "$E" == "button_dir_ROI_file_set" ]] && on_button_dir_ROI_file_set
	[[ "$E" == "button_dir_data_file_set" ]] && on_button_dir_data_file_set
	[[ "$E" == "button_dir_work_file_set" ]] && on_button_dir_work_file_set
	[[ "$E" == "button_file_sub_file_set" ]] && on_button_file_sub_file_set
	[[ "$E" == "left_toggled" ]] && on_left_toggled
	[[ "$E" == "right_toggled" ]] && on_right_toggled
	[[ "$E" == "step0_toggled" ]] && on_step0_toggled
	[[ "$E" == "step1_toggled" ]] && on_step1_toggled
	[[ "$E" == "step2_toggled" ]] && on_step2_toggled
	[[ "$E" == "step3_toggled" ]] && on_step3_toggled
	[[ "$E" == "step4_toggled" ]] && on_step4_toggled
	[[ "$E" == "step5_toggled" ]] && on_step5_toggled
	[[ "$E" == "step16_toggled" ]] && on_step16_toggled
	[[ "$E" == "step6_toggled" ]] && on_step6_toggled
	[[ "$E" == "step7_toggled" ]] && on_step7_toggled
	[[ "$E" == "step8_toggled" ]] && on_step8_toggled
	[[ "$E" == "step9_toggled" ]] && on_step9_toggled
	[[ "$E" == "step10_toggled" ]] && on_step10_toggled
	[[ "$E" == "step17_toggled" ]] && on_step17_toggled
	[[ "$E" == "button_dir_spm_file_set" ]] && on_button_dir_spm_file_set
	[[ "$E" == "button_file_temp_file_set" ]] && on_button_file_temp_file_set
	[[ "$E" == "run_clicked" ]] && on_run_clicked
	[[ "$E" == "stop_clicked" ]] && on_stop_clicked
	[[ "$E" == "progress_clicked" ]] && on_progress_clicked
	[[ "$E" == "log_clicked" ]] && on_log_clicked
done
