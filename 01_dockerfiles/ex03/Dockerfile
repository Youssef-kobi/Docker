FROM ubuntu

RUN apt-get update && apt-get upgrade -y && \
apt-get install -y openssh-server ca-certificates postfix tzdata

RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh
RUN chmod 777 ./script.deb.sh && ./script.deb.sh

RUN apt-get install -y gitlab-ce
RUN  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
echo "external_url 'https://192.168.99.103'" > /etc/gitlab/gitlab.rb
echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb
echo "nginx['redirect_http_to_https_port'] = 8080" >> /etc/gitlab/gitlab.rb
echo "letsencrypt['enable'] = true" >> /etc/gitlab/gitlab.rb
echo "gitlab_rails['gitlab_shell_ssh_port'] = 8022"  >> /etc/gitlab/gitlab.rb
echo "grafana['enable'] = false"  >> /etc/gitlab/gitlab.rb
echo "Port 8022" >> /etc/ssh/sshd_config
service ssh restart

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null