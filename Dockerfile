FROM ubuntu
COPY binary-arithmetic.cpp .
RUN apt update -y
RUN apt install g++ -y
RUN g++ binary-arithmetic.cpp -o binary-arithmetic 
CMD ["./binary-arithmetic"]

