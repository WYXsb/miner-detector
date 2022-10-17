{
    bpftrace hxy.bt                 > ../log/container_manage.log
}&

{
    bpftrace file_write_monitor.bt  > ../log/file_write_monitor.log
}&

{
    stdbuf -oL ../build/minerdetect            > ../log/minerdetect.log
}&

{
    stdbuf -oL ../build/docker_monitor         > ../log/docker_monitor.log
}&

{
    stdbuf -oL ../build/bashreadline           > ../log/bashreadline.log
}&
