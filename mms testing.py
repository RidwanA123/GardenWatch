import os
from twilio.rest import Client

def send_mms():
    account_sid = "AC1d20c171fb735b195dadb5144e1c7cfe"
    auth_token = "8aaa35cba7f748e63b8df36836743996"
    client = Client(account_sid, auth_token)

    message = client.messages \
        .create(
            body='Fuggin Pedo',
            media_url='https://raw.githubusercontent.com/dianephan/flask_upload_photos/main/UPLOADS/DRAW_THE_OWL_MEME.png',
            from_='+16108903881',
            to='+12262200398'
        )

    print(message.sid)

if __name__ == '__main__':
    send_mms()
