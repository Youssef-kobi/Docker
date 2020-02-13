FROM debian

ENV TS3SERVER_LICENSE=accept

RUN apt-get update -y && \
    apt-get install wget bzip2 -y && \
    wget  https://files.teamspeak-services.com/releases/server/3.11.0/teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
	tar -xvf teamspeak3-server_linux_amd64-3.11.0.tar.bz2

EXPOSE 9987/udp 10011 30033

ENTRYPOINT ["./teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
# docker run --rm -p 9987:9987/udp -p 10011:10011 -p 30033:30033 yel-kobi/byotss
