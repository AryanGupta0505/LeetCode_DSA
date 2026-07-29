# Write your MySQL query statement below
select Signups.user_id,ROUND(IFNULL(AVG(Confirmations.action = 'confirmed'), 0), 2) AS confirmation_rate from Signups left join Confirmations on Signups.user_id=Confirmations.user_id group by user_id;
