# Set the working directory
# !!! Need to change this on every PC
setwd("/home/musr/Desktop/dev/Learning/Cpp/MN_Lab_2/data")
wyniki.data <- read.csv(file="wyniki.csv")
 
 
plot(wyniki.data$x, wyniki.data$f.x., type="b", xlim=NULL, ylim=NULL, col="blue", xlab="x",ylab="f(x), Q(x)", pch=20)
lines(wyniki.data$x, wyniki.data$Q.x., type="b", xlim=NULL, ylim=NULL, col="red", pch=20)
legend("topleft",title="Legenda", legend=c("f(x)","Q(x)"), col=c("blue","red"), lty=1:1, cex=1.2)

plot(wyniki.data$x, wyniki.data$f.x., type="l", xlim=NULL, ylim=NULL, col="blue", xlab="x",ylab="f(x), Q(x)", pch=20)
lines(wyniki.data$x, wyniki.data$Q.x., type="l", xlim=NULL, ylim=NULL, col="red", pch=20)
legend("topleft",title="Legenda", legend=c("f(x)","Q(x)"), col=c("blue","red"), lty=1:1, cex=1.2)

