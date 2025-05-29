# My Teams
The project in question is a collaborative communication application, inspired by the known Microsoft Teams.

## Desired Features
A collaborative communication application is a service able to manage severall communication teams, where discussion are organised like following:

- threads (initial post and additional comments) in a specific channel
- discussion (personnal messages)

Here are the features implemented :

- Creating/Joining/Leaving a team
- Creating a user
- Creating a channel in a team
- Creating a thread in a channel
- Creating a comment in a thread
- Saving & restoring users, teams, channels, threads & associated comments
- Personnal discussion (from a user to an other)
- Saving & restoring personnal discussion

## CaJu Protocol
The definition and explanation of the CaJu protocol can be found in this repository, in the file: [RFC-Protocol.txt](https://github.com/EpitechPromo2027/B-NWP-400-PAR-4-1-myteams-julia.marcal-bomfa/blob/main/RFC-Protocol.txt)

## Build
In order to build our project we simply used one make file, which is responsible to compile both of the files needed: myteams_cli and myteams_server

You can easily compile it with the following command (while being at root):

```
make
```

## Run
In order to run our project you can use the following commands:

Server:
```
./myteams_cli 127.0.0.1 [port_num]
```

Client:
```
./myteams_server [port_num]
```
