FROM debian

RUN apt-get update && apt-get upgrade -y && \
apt-get install -y curl  openssh-server ca-certificates openssl  postfix tzdata openssl

#RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 ./script.deb.sh && ./script.deb.sh
RUN curl -s https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install -y gitlab-ce

RUN mkdir -p /etc/gitlab/ssl && chmod 755 /etc/gitlab/ssl && openssl req -x509 -days 365 -newkey rsa:4096 -nodes -keyout "/etc/gitlab/ssl/ab.key" -out "/etc/gitlab/ssl/ab.crt" -subj "/C=MA/"

RUN echo "external_url 'https://192.168.99.107'" > /etc/gitlab/gitlab.rb &&\
echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb &&\
echo "letsencrypt['enable'] = false" >> /etc/gitlab/gitlab.rb &&\
echo "gitlab_rails['gitlab_shell_ssh_port'] = 1337"  >> /etc/gitlab/gitlab.rb &&\
echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/ab.crt\"" >> /etc/gitlab/gitlab.rb &&\
echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/ab.key\"" >> /etc/gitlab/gitlab.rb && \
echo "Port 1337" >> /etc/ssh/sshd_config

RUN service ssh restart

EXPOSE 80 443 1337

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && service ssh restart && gitlab-ctl tail 
