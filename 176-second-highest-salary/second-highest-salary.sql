# Write your MySQL query statement below
Select max(distinct(salary)) as SecondHighestSalary from Employee where salary<>(Select max(distinct(salary)) from Employee);