FROM ubuntu:18.04

RUN apt-get update && \
	apt-get upgrade -y && apt-get install -y dialog apt-utils && \
	apt-get install -y curl openssh-server ca-certificates postfix
	
RUN	curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash && \
	apt-get install -y gitlab-ce tzdata && \
	apt update && apt-get clean

EXPOSE 80 22 443

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null