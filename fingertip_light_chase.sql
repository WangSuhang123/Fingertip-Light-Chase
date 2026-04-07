/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 80032
Source Host           : localhost:3306
Source Database       : fingertip_light_chase

Target Server Type    : MYSQL
Target Server Version : 80032
File Encoding         : 65001

Date: 2026-03-29 22:04:22
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for articleinfo
-- ----------------------------
DROP TABLE IF EXISTS `articleinfo`;
CREATE TABLE `articleinfo` (
  `ArticleID` int unsigned NOT NULL AUTO_INCREMENT COMMENT '文章唯一ID（自增主键）',
  `ArticleName` varchar(200) NOT NULL COMMENT '文章名称/标题',
  `Author` varchar(50) NOT NULL COMMENT '文章作者',
  `Content` longtext NOT NULL COMMENT '文章正文内容',
  `PublishTime` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '文章发布/创建时间',
  PRIMARY KEY (`ArticleID`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='文章信息表（独立表）';

-- ----------------------------
-- Table structure for competitions
-- ----------------------------
DROP TABLE IF EXISTS `competitions`;
CREATE TABLE `competitions` (
  `CompID` int unsigned NOT NULL AUTO_INCREMENT COMMENT '赛事唯一ID',
  `CompName` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '比赛名称',
  `ArticleID` int unsigned NOT NULL COMMENT '关联的文章ID',
  `CreatorID` int unsigned NOT NULL COMMENT '创建者ID',
  `TargetSchool` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '目标学校',
  `StartTime` datetime NOT NULL COMMENT '开始时间',
  `EndTime` datetime NOT NULL COMMENT '结束时间',
  `IsActive` tinyint NOT NULL DEFAULT '1' COMMENT '状态',
  `CreatedAt` datetime DEFAULT CURRENT_TIMESTAMP,
  `DurationMinutes` int NOT NULL COMMENT '比赛时长(秒)',
  PRIMARY KEY (`CompID`),
  KEY `idx_school` (`TargetSchool`),
  KEY `fk_comp_article` (`ArticleID`),
  KEY `fk_comp_creator` (`CreatorID`),
  CONSTRAINT `fk_comp_article` FOREIGN KEY (`ArticleID`) REFERENCES `articleinfo` (`ArticleID`) ON DELETE CASCADE,
  CONSTRAINT `fk_comp_creator` FOREIGN KEY (`CreatorID`) REFERENCES `userinfo` (`UserID`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='赛事发布表';

-- ----------------------------
-- Table structure for competition_records
-- ----------------------------
DROP TABLE IF EXISTS `competition_records`;
CREATE TABLE `competition_records` (
  `RecordID` int unsigned NOT NULL AUTO_INCREMENT,
  `CompID` int unsigned NOT NULL,
  `UserID` int unsigned NOT NULL,
  `WPM` int unsigned NOT NULL DEFAULT '0',
  `Accuracy` decimal(5,2) NOT NULL DEFAULT '0.00',
  `TimeUsed` int unsigned NOT NULL COMMENT '耗时(秒)',
  `CorrectCount` int unsigned NOT NULL,
  `ErrorCount` int unsigned NOT NULL,
  `FinalScore` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '综合评分 (WPM * 准确率)',
  `SubmitTime` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`RecordID`),
  UNIQUE KEY `uk_user_comp` (`CompID`,`UserID`),
  KEY `idx_comp_score` (`CompID`,`WPM` DESC,`Accuracy` DESC),
  KEY `fk_record_user` (`UserID`),
  CONSTRAINT `fk_record_comp` FOREIGN KEY (`CompID`) REFERENCES `competitions` (`CompID`) ON DELETE CASCADE,
  CONSTRAINT `fk_record_user` FOREIGN KEY (`UserID`) REFERENCES `userinfo` (`UserID`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户参赛成绩表';

-- ----------------------------
-- Table structure for typing_practice_records
-- ----------------------------
DROP TABLE IF EXISTS `typing_practice_records`;
CREATE TABLE `typing_practice_records` (
  `PracticeID` int unsigned NOT NULL AUTO_INCREMENT COMMENT '练习记录唯一ID',
  `UserID` int unsigned NOT NULL COMMENT '用户ID',
  `TotalChars` int unsigned NOT NULL COMMENT '原文总字数',
  `TypedChars` int unsigned NOT NULL COMMENT '用户输入字数',
  `CorrectChars` int unsigned NOT NULL COMMENT '正确字数',
  `ErrorChars` int unsigned NOT NULL COMMENT '错误字数',
  `WPM` smallint unsigned NOT NULL DEFAULT '0' COMMENT '打字速度(WPM)',
  `Accuracy` decimal(5,2) NOT NULL DEFAULT '0.00' COMMENT '准确率(%)',
  `UsedSeconds` int unsigned NOT NULL COMMENT '练习耗时(秒)',
  `PracticeTime` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '练习时间',
  `ArticleID` int unsigned NOT NULL COMMENT '关联文章ID',
  PRIMARY KEY (`PracticeID`),
  KEY `idx_user_practice` (`UserID`),
  KEY `idx_practice_time` (`PracticeTime`),
  KEY `idx_wpm` (`WPM` DESC),
  KEY `idx_article` (`ArticleID`),
  CONSTRAINT `fk_practice_article` FOREIGN KEY (`ArticleID`) REFERENCES `articleinfo` (`ArticleID`) ON DELETE CASCADE,
  CONSTRAINT `fk_practice_user` FOREIGN KEY (`UserID`) REFERENCES `userinfo` (`UserID`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户打字练习记录表';

-- ----------------------------
-- Table structure for userinfo
-- ----------------------------
DROP TABLE IF EXISTS `userinfo`;
CREATE TABLE `userinfo` (
  `UserID` int unsigned NOT NULL AUTO_INCREMENT COMMENT '用户唯一ID（自增主键）',
  `UserName` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '用户姓名（汉字/英文，可混合）',
  `Password` varchar(64) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '用户密码（加密存储，不可存明文）',
  `StudentID` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '学生学号（仅数字）',
  `SchoolName` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '学校名称',
  `EMail` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '用户邮箱（唯一，用于注册/登录）',
  `UserStatus` tinyint NOT NULL DEFAULT '0' COMMENT '用户权限：0=普通用户，1=管理员，2=禁用用户',
  PRIMARY KEY (`UserID`),
  UNIQUE KEY `uk_email` (`EMail`),
  CONSTRAINT `userinfo_chk_1` CHECK (regexp_like(`UserName`,_utf8mb3'^([\\x{4e00}-\\x{9fa5}]|[a-zA-Z])+$',_utf8mb3'u')),
  CONSTRAINT `userinfo_chk_2` CHECK (regexp_like(`StudentID`,_utf8mb3'^[0-9]+$')),
  CONSTRAINT `userinfo_chk_3` CHECK ((`UserStatus` in (0,1,2)))
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户信息表（含权限控制，所有字段非空）';
