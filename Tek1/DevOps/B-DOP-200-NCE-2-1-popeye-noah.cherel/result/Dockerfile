FROM node:12-alpine

ADD . /result

WORKDIR /result

RUN npm install

EXPOSE 80

CMD ["node", "server.js"]