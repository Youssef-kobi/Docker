from ruby

RUN apt update -y && \
apt upgrade -y && \
apt install -y sqlite3 nodejs build-essential libpq-dev

ONBUILD COPY app  /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD EXPOSE 3000

ONBUILD RUN gem install bundler
ONBUILD RUN bundle update --bundler
ONBUILD RUN bundle install

ONBUILD RUN bundle exec rake db:migrate
ONBUILD RUN bundle exec rake db:seed
