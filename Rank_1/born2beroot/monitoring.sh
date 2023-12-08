#!/bin/sh

arc=$(uname -a)
proc=$(nproc)
vproc=$(cat /proc/cpuinfo | grep processor | wc -l)
pram=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2 * 100}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
pdisk=$(df -h --total | awk '$1 == "total" {print $5}')
udisk=$(df -h --total | awk '$1 == "total" {print substr($3, 1, length($3)-1)}')
tdisk=$(df -h --total | awk '$1 == "total" {print $2}')
cpu_usage=$(cat /proc/stat | awk '$1 == "cpu" {printf("%.2f%%"), ($2+$4)*100/($2+$4+$5)}')
last_reboot=$(last reboot | awk 'NR==1 {print $5, $6, $7, $8}')
lvm=$(lsblk | grep lvm | awk '{if ($1) {print "yes";exit} else {print "no"}}')
connects=$(netstat -an | grep ESTABLISHED | wc -l)
user=$(who | wc -l)
ip=$(hostname -I)
mac=$(ip a | grep ether | awk '{print $2}')
sudo=$(journalctl _COMM=sudo | grep -c COMMAND)

wall "#Architecture: ${arc}
#CPU physical: ${proc}
#vCPU: ${vproc}
#Memory usage: ${uram}/${tram}MB (${pram}%)
#Disk Usage: ${udisk}/${tdisk} (${pdisk})
#CPU load: ${cpu_usage}
#Last reboot: ${last_reboot}
#LVM use: ${lvm}
#Connections TCP: ${connects} ESTABLISHED
#User log: ${user}
#Network: IP ${ip} (${mac})
#Sudo: ${sudo} cmd"
