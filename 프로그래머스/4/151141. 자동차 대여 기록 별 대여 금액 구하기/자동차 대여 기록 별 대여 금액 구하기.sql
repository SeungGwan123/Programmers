with history as(
    select c.daily_fee, datediff(h.end_date,h.start_date)+1 date, h.history_id,
        case
            when datediff(h.end_date,h.start_date)+1>=90 then '90일 이상'
            when datediff(h.end_date,h.start_date)+1>=30 then '30일 이상'
            when datediff(h.end_date,h.start_date)+1>=7 then '7일 이상'
            else null
        end date_type
    from car_rental_company_car c, car_rental_company_rental_history h
    where c.car_id = h.car_id and c.car_type = '트럭'
    #group by h.car_id
),
plan as(
    select duration_type, 1-(discount_rate/100) discount_rate
    from car_rental_company_discount_plan
    where car_type = '트럭'
)

select h.history_id HISTORY_ID, 
    max(case
        when h.date>=90 and p.duration_type like '90%' then floor(h.daily_fee*discount_rate*date)
        when h.date>=30 and p.duration_type like '30%' then floor(h.daily_fee*discount_rate*date)
        when h.date>=7 and p.duration_type like '7%' then floor(h.daily_fee*discount_rate*date)
        when h.date<7 then floor(h.daily_fee*date)
    end) FEE
from history h left join plan p 
on h.date_type = p.duration_type
group by history_id
order by fee desc, history_id desc

/*
HISTORY_ID  FEE
724 6336960
681 5356240
630 4791360
...
711 107000
705 107000
627 107000
524 107000

*/