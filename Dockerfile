FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install g++ -y
RUN apt install cmake -y
RUN apt-get install libboost-all-dev -y
RUN apt-get install zlib1g-dev 

RUN mkdir HighloadCup2018
COPY . /HighloadCup2018/

RUN cd HighloadCup2018/Build/ && bash build.sh

EXPOSE 80

CMD /HighloadCup2018/Build/Release/Server --ip 0.0.0.0 --port 80