FROM gcc:14.2.0

WORKDIR /var/www/issue

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install sudo nano curl -y

RUN curl -sL https://deb.nodesource.com/setup_22.x | bash -
RUN apt-get install nodejs -y
RUN npm install --global yarn

COPY .gitignore .gitignore ./
COPY package.json package.json ./
COPY tsconfig.json tsconfig.json ./

RUN npm install -g bun
RUN yarn install