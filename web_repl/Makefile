all:

upload:
	rsync -a -v --progress --inplace --relative repl.html js/*.js css/*.css $$__HOMEPAGE_REMOTE_PATH/__TEMP-microperl-web-repl-v1/

upload_stable:
	rsync -a -v --progress --inplace --relative repl.html js/*.js css/*.css $$__HOMEPAGE_REMOTE_PATH/microperl-web-repl-v1/
