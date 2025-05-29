# AREA

## Overview
The AREA project consists in the creation of an application that functions similarly to IFTTT and/or Zapier.
The project is divided in 3 parts:

- A server to provide the logic for actions and reactions.
- A web application to use the app from a browser.
- A mobile application to use the app from a phone.

### Built with:
- **Frontend**: Next.js
- **Mobile Frontend**: Flutter
- **Backend**: C# .NET
- **Database**: MySQL
- **Deployment**: Docker

---

## Getting Started

### Prerequisites
Ensure the following are installed:
- **.NET SDK**
- **Next.js & npm**
- **Flutter**
- **Docker**
- **MySQL**

### Installation

1. **Clone the repository**
    ```bash
    git clone https://github.com/EpitechPromo2027/B-DEV-500-PAR-5-1-area-cheryne.benali.git
    cd B-DEV-500-PAR-5-1-area-cheryne.benali
    ```

2. **Start all the services with the docker-compose**

    When in the root of the repository
    ```bash
    docker-compose up --build
    ```

    This command will start running:
   - The back-end

     Open [http://localhost:8080](http://localhost:8080) with your browser to access swagger.
   - Web front-end

     Open [http://localhost:8081](http://localhost:8081) with your browser to acces the web client. 
   - Mobile front-end
    
## API Reference

The API allows users to manage actions and triggers.

### Authentication

- **Login**
    - **URL**: `/api/auth/login`
    - **Method**: `POST`
    - **Description**: Authenticates a user and returns a JWT token.
    - **Request Body**:
      ```json
      {
          "username": "student01",
          "password": "your_password"
      }
      ```
    - **Response**:
      ```json
      {
        "message": "response_message",
        "token": "your_token",
        "role": "your_role"
      }
      ```

- **Register**
    - **URL**: `/api/user`
    - **Method**: `POST`
    - **Description**: Registers a new user.
    - **Request Body**:
      ```json
      {
      "email": "your_email",
      "password": "your_password",
      "username": "your_username",
      "authProvider": "string",
      "providerId": "string",
      "userType": "string"
      }
      ```
      
## Swagger Documentation
![image](https://github.com/user-attachments/assets/9887d1c9-82bd-4664-bcd5-659a9ce2aa40)


## Dockerfile Configuration

The application is containerized using separate `Dockerfiles` for the backend, frontend, and mobile frontend, coordinated through a `docker-compose.yml`. 

This setup enables seamless orchestration and straightforward configuration across different environments.

# Services and Widgets Implemented

## 1. Trello

**Reactions:**
- **Create list in board**: Creates a new list in a specified Trello board.
- **Create card in list**: Adds a new card with a description in a specified list on Trello.

---

## 2. Discord

**Reactions:**
- **List reactions to message**: Lists all reactions on a message in a Discord channel.
- **Add reaction to message**: Adds a reaction to a message in a Discord channel.
- **Clear all reactions to message**: Clears all reactions on a message in a Discord channel.
- **Remove Role From Member**: Removes a role from a member on Discord.
- **Updates server description**: Updates the description of a specified Discord channel.
- **Add music Bot**: Adds a music bot to a channel on Discord.
- **Add Role To Member**: Assigns a role to a Discord member in a server.
- **Send private message to a user**: Sends a direct message to a specified user on Discord.
- **Remove reaction to message**: Removes a specific reaction from a message in a Discord channel.
- **Create Text Channel**: Creates a text channel on a specified server.
- **Remove Member**: Removes a member from a server.
- **Send Message To Channel**: Sends a message in a specified channel.

---

## 3. OpenWeather

**Actions:**
- **CheckHeatWave**: Checks if a specified city is experiencing a heat wave.
- **IsSunny**: Verifies if it is sunny in a specified city.
- **CheckBelowZero**: Checks if the temperature is below 0°C in a specified city.
- **CheckBtwTenAndTwenty**: Checks if the temperature is between 10°C and 20°C in a specified city.
- **IsRaining**: Checks if it is raining in a specified city.
- **CheckHumidity**: Retrieves the humidity level in a specified city.
- **CheckHumidityAbove60**: Checks if the humidity level is above 60% in a specified city.
- **IsSnowing**: Checks if it is snowing in a specified city.
- **CheckAboveZero**: Checks if the temperature is above 0°C in a specified city.

---

## 4. Asana

**Reactions:**
- **Add comment to task**: Adds a comment to a specified Asana task.
- **Create subtask**: Creates a subtask within an Asana task.
- **Update task**: Updates details of an Asana task.
- **Duplicate task**: Duplicates a task in Asana, allowing for name and description customization.
- **Delete task**: Deletes a task in Asana.
- **Create new task**: Creates a new task in a specified Asana workspace.
- 
---

## 5. GitHub

**Reactions:**
- **Star a repo**: Stars a repository on GitHub.
- **Create issue**: Creates an issue in a specified repository on GitHub.

---

## 6. Reddit

**Reactions:**
- **Send a comment on a subreddit**: Posts a comment on a specified subreddit.
- **Send private message to a user**: Sends a private message to a specified user on Reddit.
- **Post to a subreddit**: Posts content to a specified subreddit.

---

## 7. Spotify

**Actions:**
- **Is music playing**: Checks if a new song is currently playing.
- **Is new playlist**: Checks if there is a new playlist.
- **Is music liked**: Verifies if the user has liked a song.

---

## 8. WorldTime

**Actions:**
- **Is Three PM**: Checks if the current time is 3 PM in a specified timezone.
- **Is Four PM**: Checks if the current time is 4 PM in a specified timezone.
- **Is Twelve AM**: Checks if the current time is 12 AM in a specified timezone.
- **Is Ten AM**: Checks if the current time is 10 AM in a specified timezone.
- **Is Eight AM**: Checks if the current time is 8 AM in a specified timezone.
- **Is Two PM**: Checks if the current time is 2 PM in a specified timezone.
- **Is Five PM**: Checks if the current time is 5 PM in a specified timezone.
- **Is One PM**: Checks if the current time is 1 PM in a specified timezone.

### Documentation

In the documentation/ folder you can find these documents:

Technical documentation → Technical information about the project.

### Contact

This project was made by

- [Angeline Schmidt - Mobile client developer](https://github.com/Angeline-schmidt)
- [Bradley Malbrouck - Web client developer](https://github.com/7Bradley7)
- [Camila Grandini - Back-end developer + DevOps](https://github.com/camilagrandinii)
- [Chéryne Benali - Back-end developer + Mobile client developer](https://github.com/Cherynee)
- [Vaéa Seyed - Web client developer + Back-end developer](https://github.com/Vamytis)

