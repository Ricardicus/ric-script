# Pull base image, using Ubuntu latest
FROM ubuntu:18.04

# Install Node.js
RUN apt-get update && apt-get install --yes curl
RUN curl -sL https://deb.nodesource.com/setup_14.x | bash -
RUN apt-get install --yes nodejs build-essential cmake bison flex

# Install meson
RUN apt install --yes software-properties-common
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update && apt-get install --yes python3.7 python3-pip python3-setuptools \
                       python3-wheel ninja-build
RUN pip3 install --upgrade pip && pip install meson==0.52.0 ninja

COPY . /src

RUN cp -r /src/doc/sphinx/buildRootMod/html /src/node/doc

WORKDIR /src/node

# Install app dependencies
RUN npm install --unsafe-perm

# Place interpreter in PATH
RUN cp ric /usr/local/bin; cp -r ../samples /src/node;

# Binds to port 3000
EXPOSE 3000

#  Defines your runtime(define default command)
# These commands unlike RUN (they are carried out in the construction of the container) are run when the container
CMD ["node", "/src/node/app.js"]
