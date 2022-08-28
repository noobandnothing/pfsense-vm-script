/*For anyone want to create runable app for Ubuntu /kubuntu  to run pfsense after boot
 ... I will share it if anyone will need to do same.
-  just put it in file.c .
- gcc file.c .*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        sleep(5);
 if(system("ls /dev/vmmon") != 0){
    system("sudo vmware-modconfig --console --install-all");
 }
        if(system("vmrun -T ws list |grep FreeBSD") != 0){
            system("sudo /etc/init.d/vmware start");
            system("vmrun start \'/home/server/vmware/FreeBSD version 10 and earlier 64-bit/FreeBSD version 10 and earlier 64-bit.vmx\'");
        }else{
            sleep(5);
        }
    }
    return 0;
}
/*
Replace FreeBSD by machine name in vmware .

  if(system("vmrun -T ws list |grep FreeBSD")

This if check if it run or no to make server always open .
as if u reboot vm ware will receive it as power off machine so server die 😂 .
so I used this trick .
also vmrun start "path to vmx  of machine which u created in vmware" .
Yeah also I used c  to use it as bin as bash crash in Ubuntu autostart .
after compiling better to move it to /usr/bin and rename it as u like.
then pick it from autostart

oof sorry guys : I forgot .
u will need to edit suderoes :
sudo visudo , change ALL to  NOPASSWORD:ALL*/
