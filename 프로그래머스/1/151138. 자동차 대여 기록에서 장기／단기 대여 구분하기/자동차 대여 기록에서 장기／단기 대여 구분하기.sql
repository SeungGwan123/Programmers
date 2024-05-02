-- 코드를 입력하세요
SELECT HISTORY_ID,CAR_ID,date_format(START_DATE,"%Y-%m-%d") as START_DATE,date_format(end_date,"%Y-%m-%d") as END_DATE,
case 
    when datediff(end_date,start_date) >=29 then '장기 대여'
    else '단기 대여'
end as RENT_TYPE
from car_rental_company_rental_history
where date_format(start_date,'%Y-%m') = '2022-09'
order by history_id desc