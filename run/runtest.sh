{
    stdbuf -oL  ../build/bashreadline           > ../log/bashreadline.log
}&

{
    stdbuf -oL ../build/docker_monitor         > ../log/docker_monitor.log
}&