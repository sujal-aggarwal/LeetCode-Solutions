# Write your MySQL query statement below
SELECT customer_id,COUNT(*) AS count_no_trans FROM visits v WHERE visit_id NOT IN (SELECT visit_id FROM transactions) GROUP BY customer_id ;