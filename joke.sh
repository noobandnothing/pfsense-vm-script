 sleep 90
 arp -a | grep XXX.XXX.XXX.XXX | grep -v incomplete
 if [ "$?" != "0" ] ;then
    sleep 2
    kill $(pidof serverr)
    rm -rf /home/server/vmware/PFserver/PFserver.vmdk
    cp -rv /home/server/vmware/Backup/PFserver.vmdk /home/server/vmware/PFserver/PFserver.vmdk
    reboot
 fi

