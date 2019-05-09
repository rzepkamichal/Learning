#ksiazka 152 - 155
# badanie hipotezy H_0: m1 = m2, alpha = 0.05

czerwona_p = c(39.722, 38.581, 42.330, 43.192, 39.429, 37.713, 37.986, 39.876, 43.037, 41.071, 42.360, 37.342, 40.268, 39.870, 41.732,
               41.528, 42.379, 38.971, 43.758, 40.617, 39.712, 43.117, 38.629, 42.588, 38.148)

czarna_p = c(41.466, 40.621, 38.332, 36.591, 40.755, 43.270, 41.567, 42.057, 41.417, 41.173, 40.469, 37.560, 40.159, 35.145, 40.063, 
             40.786, 44.170, 36.898, 40.743, 37.562, 37.469, 42.675, 41.327, 40.931, 38.510)
amount = 25

"sigma1 i sigma2 nie sa znane, nie wiemy tez czy sa rowne, zatem, aby wybrac dobra statystyke testowa nalezy najpierw wykonac
test hipotezy H_0: sigma1^2 = sigma2^2 na przyjetym poziomie ufnosci pozwalajacy stwierdzic, czy nieznane wariancje mozna uznac za rowne."

# badanie H_0: sugna1^2 = sigma2^2, alpha = 0.05

#wartosci oczekiwane z proby

sum_czerwone = 0
sum_czarne = 0

for(i in 1:amount){
  sum_czerwone = sum_czerwone + czerwona_p[i]
  sum_czarne = sum_czarne + czarna_p[i]
}

avg_czerwone = sum_czerwone/amount
avg_czarne = sum_czarne/amount

#print(avg_czerwone)
#print(avg_czarne)

variance_czerwone = 0
variance_czarne = 0

for(i in 1:amount){
  variance_czerwone = variance_czerwone + (avg_czerwone - czerwona_p[i])^2
  variance_czarne = variance_czarne + (avg_czarne - czarna_p[i])^2
}

variance_czerwone = variance_czerwone/amount
variance_czarne = variance_czarne/amount

unbiased_variance_est_czerwone = amount * variance_czerwone/(amount - 1)
unbiased_variance_est_czarne = amount * variance_czarne/(amount - 1)

# stosunek f

if (unbiased_variance_est_czerwone >= unbiased_variance_est_czarne){
  f = unbiased_variance_est_czerwone / unbiased_variance_est_czarne
}else{
  f = unbiased_variance_est_czarne / unbiased_variance_est_czerwone
}

#kwantyl F-rozkladu f(1-0.05, 24, 24) = 1.98 - z tablic

quantile = 1.98

print(f)
print(f < quantile)

#WYNIK TRUE - nie ma podstaw do odrzucenia hipotezy H_0: sugna1^2 = sigma2^2, alpha = 0.05
#Mozna zatem skorzystac z testu t-Studenta dla nieznanych, ale rownych sigma1, sigma2

T = (avg_czerwone - avg_czarne)/sqrt((amount*(variance_czerwone+variance_czarne)/(2*amount-2))*(2/amount))

print(T)

#BRAK PODSTAW DO ODRZUCENIA HIPOTEZY - T nie nalezy do przedzialu (-inf, -1.96) U (1.96, +inf) - przedzial wziety z tablic

#BRAK PODSTAW DO ODRZUCENIA HIPOTEZY, ZE OBA RODZAJE OWOCOW MAJA JEDNAKOWA ZAWARTOSC WITAMINY C


