FROM ubuntu:20.04

RUN apt-get update
RUN apt-get install g++-9 -y
RUN alias g++='g++-9'

RUN apt-get install python3.8 python3-pip -y
RUN alias python='python3'
RUN pip3 install numba numpy scipy scikit-learn networkx

