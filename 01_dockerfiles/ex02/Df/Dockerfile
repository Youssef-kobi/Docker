from ruby

RUN apt update -y && \
apt upgrade -y

ONBUILD COPY ./helloWorld  /opt/app
ONBUILD WORKDIR /opt/app 
ONBUILD RUN bundle install

ONBUILD RUN bundle exec rake db:migrate
ONBUILD RUN bundle exec rake db:seed
