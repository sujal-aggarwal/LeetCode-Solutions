# Write your MySQL query statement below
SELECT tweet_id FROM (SELECT tweet_id,LENGTH(content) AS length FROM tweets) AS s WHERE length>15;