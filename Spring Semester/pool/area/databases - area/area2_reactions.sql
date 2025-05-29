-- MySQL dump 10.13  Distrib 8.0.38, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: area2
-- ------------------------------------------------------
-- Server version	8.0.39

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `reactions`
--

DROP TABLE IF EXISTS `reactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `reactions` (
  `uuid` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `service_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`uuid`),
  KEY `id_service_reaction_index` (`service_id`),
  CONSTRAINT `id_service_reaction_index` FOREIGN KEY (`service_id`) REFERENCES `services` (`uuid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reactions`
--

LOCK TABLES `reactions` WRITE;
/*!40000 ALTER TABLE `reactions` DISABLE KEYS */;
INSERT INTO `reactions` VALUES ('11fec3e1-b9b1-466b-966c-a3de87f7309a','525001e0-382b-4dac-9e9c-4e8fce01bc27','star a repo','create an issue on github','2024-10-31 13:01:47','2024-10-31 13:01:47'),('356dc46e-bd95-4b37-9c24-7a23b460ae00','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb','Create list in board','for trello to create a new list in a given board','2024-11-01 00:01:15','2024-11-01 00:01:15'),('7fb3aa39-9c5c-44be-b6a3-a7c479f25c9e','2600feb8-fb1b-4926-b8bf-124727c71069','Updates serveur description on discord','Updates the description of a specific channel on discord','2024-10-07 10:31:48','2024-10-07 10:31:48'),('a50c22d2-1ed0-4d69-9aee-b52f5d9a87fd','2600feb8-fb1b-4926-b8bf-124727c71069','Send private message to an user','Sends a message to a specific user on discord','2024-10-07 10:30:06','2024-10-07 10:30:06'),('b3927fbc-6f2f-43e7-97b3-4947cf9cb6c5','2600feb8-fb1b-4926-b8bf-124727c71069','Create Text Channel','Creates a text channel on a specific server','2024-10-22 12:20:44','2024-10-22 12:20:44'),('c33ab438-bbb4-4aa5-aeec-dacdac48c65e','525001e0-382b-4dac-9e9c-4e8fce01bc27','create issue','create an issue on github','2024-10-31 13:00:38','2024-10-31 13:00:38'),('ee9aa6d2-1d7b-464c-9aa0-d543d35e05d4','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb','Create card in list','for trello to create a new card with its description in a given list','2024-11-01 00:02:08','2024-11-01 00:02:08'),('f132e447-af06-4b99-b40d-f2df27180a11','2600feb8-fb1b-4926-b8bf-124727c71069','Send Message To Channel','Sends a message on a specific channel','2024-10-22 12:25:58','2024-10-22 12:25:58'),('f5ac05b7-2a02-4e85-8b40-a283de70a1b2','4fb596d1-6295-428f-ae1d-40ce0b618f81','add-pic-comment','add a comment into a person\'s picture','2024-09-30 18:33:47','2024-09-30 18:33:47');
/*!40000 ALTER TABLE `reactions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-11-01 18:10:59
