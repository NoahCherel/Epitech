FROM maven:3.8.4-jdk-11-slim AS builder

ADD . /worker/

WORKDIR /worker

RUN mvn dependency:resolve

RUN mkdir /target

RUN mvn package > /target/worker-jar-with-dependencies.jar

FROM openjdk:11-jre-slim

WORKDIR /worker

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]