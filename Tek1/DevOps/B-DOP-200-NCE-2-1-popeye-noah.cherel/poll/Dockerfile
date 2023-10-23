FROM python:3

RUN pip3 install -r requirements.txt

ADD . /poll/
WORKDIR /poll

EXPOSE 80

CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]