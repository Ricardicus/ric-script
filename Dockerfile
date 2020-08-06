# Pull base image, using Ubuntu latest
FROM ubuntu:latest

# Install Node.js
RUN apt-get update && apt-get install --yes curl
RUN curl -sL https://deb.nodesource.com/setup_14.x | bash -
RUN apt-get install --yes nodejs build-essential bison flex

WORKDIR /node

COPY ./node/ /node
COPY . /src

# Install app dependencies
RUN npm install

# Build interpreter, place it in PATH
RUN cd /src; make; cp ric /usr/local/bin; cp -r samples /node;

# Binds to port 3000
EXPOSE 3000

#  Defines your runtime(define default command)
# These commands unlike RUN (they are carried out in the construction of the container) are run when the container
CMD ["node", "/node/app.js"]
