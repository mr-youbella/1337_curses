# Born2beroot

Linux server administration inside a virtual machine, with an emphasis on storage, access control, and monitoring.

[Repository](../README.md) · **Linux / virtualization / system administration** · **Score: 125**

## Project overview

Born2beroot introduces the setup and administration of a minimal Linux server. The work is performed inside a virtual machine rather than compiled into an executable.

This portfolio records an evaluation score of **125**. The [subject, version 5.2](../Subjects/Born2beroot.subject.pdf), is included here; the virtual machine, configuration files, monitoring script, and disk signature are not. The overview below describes the subject's scope. The specific operating system, partition layout, and bonus services used for my evaluation are not recorded in this collection.

## What the subject covers

| Area | Required work |
| --- | --- |
| Virtualization | A server VM using VirtualBox or UTM, with Debian or Rocky Linux and no graphical server. |
| Storage | Encrypted partitions managed with LVM. |
| Access control | User and group administration, password aging and complexity rules, and restricted `sudo` configuration. |
| Remote access | SSH on port 4242, with direct root login disabled. |
| Firewall | UFW for Debian or firewalld for Rocky, with the mandatory setup exposing only SSH. |
| System protection | AppArmor for Debian or SELinux for Rocky, active at startup. |
| Monitoring | A Bash script reporting system state to terminals at startup and every ten minutes. |

The monitoring report includes CPU and memory usage, storage usage, boot time, LVM status, connections, logged-in users, network addresses, and the number of `sudo` commands. The subject connects shell scripting with scheduling and system inspection, while the administration work requires understanding how the services and policies fit together.

## Bonus scope

The subject offers a more detailed partition layout, a WordPress site using **lighttpd, MariaDB, and PHP**, and an additional service chosen by the student. These are subject options; the score alone does not establish which services or configuration were used.

## Viewing and running the project

Start with the [subject PDF](../Subjects/Born2beroot.subject.pdf) for the setup and evaluation requirements. There is no local build target or runnable VM in this repository. Reproducing the evaluated environment would require its actual VM and configuration details.

The subject's submission centers on documentation and a virtual-disk signature, with the VM itself kept outside Git. No signature or implementation artifacts have been added here.

[Back to 1337 Curses](../README.md)
