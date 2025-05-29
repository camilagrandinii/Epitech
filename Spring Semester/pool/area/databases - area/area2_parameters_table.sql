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
-- Table structure for table `parameters_table`
--

DROP TABLE IF EXISTS `parameters_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `parameters_table` (
  `uuid` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `id_service` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `id_action` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `id_reaction` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `parameter` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`uuid`),
  KEY `id_service_data` (`id_service`),
  KEY `id_action_data` (`id_action`),
  KEY `id_reactions_data` (`id_reaction`),
  CONSTRAINT `id_action_data` FOREIGN KEY (`id_action`) REFERENCES `actions` (`uuid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id_reactions_data` FOREIGN KEY (`id_reaction`) REFERENCES `reactions` (`uuid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id_service_data` FOREIGN KEY (`id_service`) REFERENCES `services` (`uuid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `parameters_table`
--

LOCK TABLES `parameters_table` WRITE;
/*!40000 ALTER TABLE `parameters_table` DISABLE KEYS */;
INSERT INTO `parameters_table` VALUES ('0693876b-fa4d-4a1f-9e4f-3ef5abe00bd3','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'ee9aa6d2-1d7b-464c-9aa0-d543d35e05d4','CardDescription'),('29db3a25-3e50-457d-a0ae-c01ff2361cef','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'7fb3aa39-9c5c-44be-b6a3-a7c479f25c9e','Channel Id'),('2f4c8ca1-79da-4a9a-98b2-76b36a1e087d','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'a50c22d2-1ed0-4d69-9aee-b52f5d9a87fd','To'),('43755024-aa31-4b5f-98a2-485d4148298a','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'ee9aa6d2-1d7b-464c-9aa0-d543d35e05d4','CardName'),('54e300d6-4fc1-4b22-990a-819490933426','525001e0-382b-4dac-9e9c-4e8fce01bc27',NULL,'c33ab438-bbb4-4aa5-aeec-dacdac48c65e','body'),('5c6465c8-a7c2-4ebc-8894-3fa68a48f940','525001e0-382b-4dac-9e9c-4e8fce01bc27',NULL,'c33ab438-bbb4-4aa5-aeec-dacdac48c65e','repo_name'),('7d397052-0b70-40ce-aad9-92c2fcc8981b','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'b3927fbc-6f2f-43e7-97b3-4947cf9cb6c5','Guild Id'),('7ed3f755-2e79-4acb-9d97-b0aba56d2f3b','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'a50c22d2-1ed0-4d69-9aee-b52f5d9a87fd','Message'),('7f265cb9-dbf1-4978-a273-a71731fe883c','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'356dc46e-bd95-4b37-9c24-7a23b460ae00','NewListName'),('93acb424-a2ad-45e2-bbc7-e4d3b2da2d32','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'f132e447-af06-4b99-b40d-f2df27180a11','Channel Id'),('adef6791-c57b-4297-8a83-26e099679002','525001e0-382b-4dac-9e9c-4e8fce01bc27',NULL,'11fec3e1-b9b1-466b-966c-a3de87f7309a','repo_name'),('b62a3443-e2b5-440a-9114-6498ebd3a650','525001e0-382b-4dac-9e9c-4e8fce01bc27',NULL,'c33ab438-bbb4-4aa5-aeec-dacdac48c65e','title'),('b9913b94-4d36-4fc9-9d1e-b4cbc7547f2a','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'ee9aa6d2-1d7b-464c-9aa0-d543d35e05d4','BoardName'),('c45d33ef-2002-435d-8856-62545f462232','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'f132e447-af06-4b99-b40d-f2df27180a11','Message To Channel'),('cd119a22-f757-4cae-b19f-dd38b13cf4f1','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'b3927fbc-6f2f-43e7-97b3-4947cf9cb6c5','Channel Name'),('eb8e13bf-2761-4b81-8d43-923a56dd007a','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'ee9aa6d2-1d7b-464c-9aa0-d543d35e05d4','ListName'),('f1f778fd-3cd4-4413-8b17-ad3a33dbe3c5','21d1d1bc-ba4d-4c12-b038-2bf1409f8dcb',NULL,'356dc46e-bd95-4b37-9c24-7a23b460ae00','BoardName'),('fa1dcb39-1947-4a5a-a0b5-81fcd8a9b790','2600feb8-fb1b-4926-b8bf-124727c71069',NULL,'7fb3aa39-9c5c-44be-b6a3-a7c479f25c9e','New Description');
/*!40000 ALTER TABLE `parameters_table` ENABLE KEYS */;
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
