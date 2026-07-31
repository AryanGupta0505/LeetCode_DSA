# Write your MySQL query statement below
-- SELECT DATE_FORMAT(date_column, '%Y-%m') AS YearMonth FROM your_table;
-- Option 1 (Most Common)
-- SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END)
-- Option 2
-- COUNT(CASE WHEN state = 'approved' THEN 1 END)

-- Here, rows that are not approved return NULL, and COUNT() ignores NULLs.
select date_format(trans_date,'%Y-%m') as month , country, count(state) as trans_count, count(case when state='approved' then 1 end) as approved_count ,sum(amount) as trans_total_amount, sum(case when state='approved' then amount else 0 end) as approved_total_amount from Transactions group by country , month;