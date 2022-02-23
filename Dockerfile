# Building documentation
FROM sphinxdoc/sphinx as sphinx-doc

RUN apt-get update && apt-get install -y doxygen

WORKDIR /doc
COPY ./doc/sphinx/ /doc/sphinx/
RUN cd /doc/sphinx && pip install -r requirements.txt && make html

FROM node:16-buster as remote-terminal

RUN apt-get update -y && apt-get install -y build-essential flex bison

# Building ric-script
WORKDIR /src/ric-script

# Install meson
COPY . /src/ric-script

ENV DOCKER_MODE 1
RUN make && make install

COPY node/ /usr/src/app/

# App directory
WORKDIR /usr/src/app

COPY --from=sphinx-doc /doc/sphinx/build/html /usr/src/app/public/doc
RUN cp -r /src/ric-script/ric /usr/bin && \
    cp -r /src/ric-script/images /usr/src/app/public/images && \
    cp -r /src/ric-script/images /usr/src/app/public/doc/images

RUN npm install
# If you are building your code for production
# RUN npm ci --only=production

EXPOSE 3000

RUN mkdir /explore

RUN mv /src/ric-script/samples /explore/samples && mv files/* /explore

RUN groupadd noobz && useradd -rm -d /explore -g noobz -u 1001 noob
USER noob

CMD [ "node", "app.js", "/explore"]
