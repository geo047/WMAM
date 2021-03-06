# Create the basic profiling information using "eagle_profile.submit" (this script) and "eagle_profile.slurm.template" scripts
# e.g. sbatch eagle_profile.submit <ngpu> 
# Now use sort and tail to remove the extra header strings "profile,itnum,ncpu,ngpu,function,time_ms"
# cat eagle_11710257_*.res | grep profile | sort -h -r | tail -n +9
# cat eagle_bracewellr_12099468*.res | grep profile | sort -h -r | tail -n +9

library(rbokeh)


## Some usefull functions
add_factor_col <- function(df,df_fact) {
  
  if( nrow(df) != length(df_fact) ) {
    message("add_factor_col() nrow(df)  should be the same as length(df_fact)")
    stop("nrow(df): ", nrow(df), "  and length(df_fact)", length(df_fact) )
  } 
  df_fact <- factor(as.vector(df_fact) )
  df_result  <- cbind(df,df_fact)
  return (df_result)
}




#df <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Mid_docker_tests\\benchmark\\new_timing.out")
# df <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_res_large.txt")
df_fact <- NULL
df_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\res_12092835_large_scatter.txt")
df_fact <- rep('singularity_s',nrow(df_ss))

df_sc <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\res_12092992_large_compact.txt")
df_fact <- cbind(df_fact,rep('singularity_c',nrow(df_sc)))


df_bs <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\bracewellr_scatter_12099907_2.txt")
df_fact <- cbind(df_fact,rep('native_s',nrow(df_bs)))

df_bc <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\bracewellr_12099468.txt")
df_fact <- cbind(df_fact,rep('native_c',nrow(df_bc)))


df_new <- read.csv(file="F:\\Docker\\Eagle_profiling_data\\bracewellr_12099468.txt")

df_all  <- rbind(df_ss,df_sc,df_bs,df_bc)
df_fact <- factor(as.vector(df_fact) )
df_all  <- cbind(df_all,df_fact)
df      <- df_all
df      <- df_ss
df      <-  df_bs 
#' df should be a dataframe (use rbind first to combine multiple is needed)
#' df_fact should be a vector of character strings, which will be converted to factors
#' N.B. to create char vector: df_fact <- rep('singularity_s',nrow(df_ss))
#'      and to add to char vector:  cbind(df_fact,rep('native_c',nrow(df_bc)))


### GPU results - total times - no HDF file i/o:
df_gpu_01 <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_compact_gpu_1_2_3_4_ncpu_01_v2.txt")  
df_gpu_02 <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_compact_gpu_1_2_3_4_ncpu_02_v2.txt")
df_gpu_04 <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_compact_gpu_1_2_3_ncpu_04.txt")
df_gpu_14 <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_compact_gpu_1_2_ncpu_14.txt")  

total_time_gpu_1 <- vector("numeric",4)
total_time_gpu_1[1] <- sum((subset(df_gpu_01, ngpu==1, c(function.,ncpu,ngpu,time_ms)))$time_ms)
total_time_gpu_1[2] <- sum((subset(df_gpu_02, ngpu==1, c(function.,ncpu,ngpu,time_ms)))$time_ms)
total_time_gpu_1[3] <- sum((subset(df_gpu_04, ngpu==1, c(function.,ncpu,ngpu,time_ms)))$time_ms)
total_time_gpu_1[4] <- sum((subset(df_gpu_14, ngpu==1, c(function.,ncpu,ngpu,time_ms)))$time_ms)
ncps_gpu_1 <- as.integer(c(1,2,4,14))
str(ncps_gpu_1)

# Plot the 1 GPU data, x axis is number of cores
library(rbokeh)
figure(title="Eagle Total Time (4 interations, dataset size = 2000 x 499829, 1 x P100 GPU LD_PRELOAD)") %>%
  ly_points(x=ncps_gpu_1, y=total_time_gpu_1/1000, hover = list(total_time_gpu_1/1000)) %>%
  y_axis(label = "Time/s", log=F) %>%
  y_range(c(-100, 1750 )) %>%
  x_range(c(0, 29 )) %>%
  x_axis(label = "Number of CPU cores") 


# Total times for 4 iterations with multiple GPUs - requires extra CPU cores or will diminish performance
which_num_cpus <- df_gpu_01 # df_gpu_01  df_gpu_02  df_gpu_04  df_gpu_14
total_gpu_1 <- sum((subset(which_num_cpus, ngpu==1, c(function.,ncpu,time_ms)))$time_ms)
total_gpu_2 <- sum((subset(which_num_cpus, ngpu==2, c(function.,ncpu,time_ms)))$time_ms)
total_gpu_3 <- sum((subset(which_num_cpus, ngpu==3, c(function.,ncpu,time_ms)))$time_ms)
total_gpu_4 <- sum((subset(which_num_cpus, ngpu==4, c(function.,ncpu,time_ms)))$time_ms)

# subset(df_gpu_02
# > total_gpu_2
# [1] 196994.9 / ms
# > total_gpu_3
# [1] 237487.3 / ms
# 
# subset(df_gpu_04
# > total_gpu_2
# [1] 274868.5 / ms
# > total_gpu_3
# [1] 178815.8 / ms  # N.B. This is the fastest time found





###
# Subset by ncpu
df[ order(df$function., df$ncpu, df$ngpu), ]
df_sub <- subset(df, ngpu==0 , c(function.,ncpu,time_ms))
df_sub <- subset(df, ngpu==0 & itnum>1 , c(function.,ncpu,time_ms)) # this will exclude the MMt computation


# combine cpu and gpu benchmarks
df <- rbind(df, df_gpu)
# subset by ngpu
df_sub <- df_sub[order(df$function.,df$ngpu),]


# Subset by function:
df_sub_calc_extBIC <- subset(df, function.=="calc_extBIC" , c(ncpu,time_ms))




### Plot the individual function results using "df"
library(rbokeh)

plot_by_function <- function(df,itter=1)
{
  df <- subset(df, (itnum==itter),c(itnum,ncpu,ngpu,time_ms,function.) )
  figure(title="Eagle time by function (4 interations, dataset size = 2000 x 499829)") %>%
      ly_points(x=ncpu, y=time_ms/1000, data = df, color = function., hover = list(time_ms,function.,ncpu,itnum)) %>%
      y_axis(label = "Time/s", log=F) %>%
      y_range(c(-10, max(df$time_ms/1000)+0.1*max(df$time_ms/1000)  )) %>%
      x_axis(label = "Number of CPU cores") 
}

plot_by_function(df_ss, itter=3)
fig <- plot_by_function(df_new, itter=1)


plot_by_function <- function(df,itter=1)
{
  df <- subset(df, (itnum==itter),c(itnum,ncpu,ngpu,time_ms,function.) )
  return (figure(title="Eagle time by function (4 interations, dataset size = 2000 x 499829)") %>%
            ly_points(x=ncpu, y=time_ms/1000, data = df, color = function., hover = list(time_ms,function.,ncpu,itnum)) %>%
            y_axis(label = "Time/s", log=F) %>%
            y_range(c(-10, max(df$time_ms/1000)+0.1*max(df$time_ms/1000)  )) %>%
            x_axis(label = "Number of CPU cores") 
  )
}
    

# plot by GPU    
figure(title="Eagle time by function (4 interations, dataset size = 2000 x 499829)") %>%
  ly_points(x=ngpu, y=time_ms, data = df, color = function., hover = list(time_ms,function.,ngpu)) %>%
  y_axis(label = "Time/ms", log=F) %>%
  y_range(c(-100, max(df$time_ms)+0.1*max(df$time_ms) )) %>%
  x_axis(label = "Number of GPUs") 



# This does not do what I want it to do!
bp_level <- paste0(df$ncpu,":",df$function.)
df_new <- cbind(df,bp_level)
df_new2 <- subset(df_new, (function.!="MMt") & (function.!="invMMt"), c(itnum,ncpu,ngpu,time_ms,bp_level))
figure(ylab = "Total Time (s)", width = 600) %>%
  ly_boxplot(bp_level, time_ms/1000,  data = df_new2 )
str(df_new2)



###############
### Compute total times and plot
# N.B. This is a Function definition, which is used on line 171 below:
sum_total_times <- function(df) {
  lev <- levels(df$df_fact)

  # initialised results vectors
  total_t_vect <- vector("numeric", length(unique(df$ncpu)) * length(lev))
  ncpu_vect <- vector("numeric", length(unique(df$ncpu))* length(lev) )
  
  factlev <- vector('character', length(unique(df$ncpu))* length(lev))
  fact_itter <- 0
  for (fact in lev) {
    
    itter <- 1
    for (ncpu_count in order(unique(df$ncpu)) ) {
      vect_ref <- fact_itter * length(unique(df$ncpu)) + itter
     
      ncpu_vect[vect_ref]    <- unique(df$ncpu)[ncpu_count]
      total_t_vect[vect_ref] <- sum((subset(df, ncpu==ncpu_vect[itter] & df_fact==fact, c(function.,ncpu,time_ms)))$time_ms)
      factlev[vect_ref] <- fact
      itter <- itter + 1 ;
    
      
    }
    fact_itter <- fact_itter + 1 ;
  }
  
  # Convert vectors to a list, add names and convert list to df
  tlist <- list(ncpu_vect,total_t_vect,factlev)
  names(tlist) <- c("ncpu","total_time","system")
  total_time_df <- as.data.frame(tlist,stringsAsFactors=T)
}


total_time_df <- sum_total_times(df)
figure(title="Eagle Total Time (4 interations, dataset size = 2000 x 499829, bracewell node)") %>%
  ly_points(x=ncpu, y=total_time/1000,00, data = total_time_df, color = system , hover = list(total_time/1000,system)) %>%
  y_axis(label = "Time/s", log=F) %>%
  y_range(c(-100, max(total_time_df$total_time/1000)+0.1*max(total_time_df$total_time/1000))) %>%
  x_axis(label = "Number of CPU cores") 



###################



### Repeats singularity scatter boxplot + hover of average total time
# N.B. The eagle_REPEATS_ss_slurm_id.txt data was created via a shell script "repeat_processing.sh" 
# likewise with:  eagle_HDF5_cs_eigenblas_slurm_id.txt
# This script added the SLURM_ID value from the .res output data filename
df_rep_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_REPEAT_cs_CRAN_slurm_id.txt") # original CRAN timing
df_rep_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_REPEATS_ss_slurm_id.txt") # eagle_REPEATS_ss.txt
df_rep_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_REPEATS_HDF5_ss_slurm_id.txt")
df_rep_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_HDF5_cs_eigenblas_slurm_id.txt") # eagle_REPEATS_ss.txt
df_rep_ss <- read.csv(file="\\\\braggflush1\\flush1\\bow355\\AMplus_new_code\\Large\\eagle_REPEAT_cs_ROWMAJOR_run_id.txt") # eagle_REPEATS_ss.txt


roundUpNice <- function(x, nice=c(1,2,4,5,6,8,10)) {
  if(length(x) != 1) stop("'x' must be of length 1")
  10^floor(log10(x)) * nice[[which(x <= 10^floor(log10(x)) * nice)[[1]]]]
}

total_time_df <- get_total_times_for_repeats(df_rep_ss) 

subset_by_num_GPU=0
subset_by_num_GPU=1
total_time_df <- subset(total_time_df, total_time_df$ngpu==subset_by_num_GPU, c(ngpu,ncpu,total_time,system))

ave_time_df <- get_average_times_for_repeats(total_time_df)


# ave_time_df$jitwhich <- paste0(ave_time_df$ncpu, ":", ave_time_df$average_time)

# The following dataframe is the 1 GPU results with added number of cores:
# tlist <- list(as.character(ncps_gpu_1),rep(1,length(ncps_gpu_1)), total_time_gpu_1)
# names(tlist) <- c("ncpu","ngpu","average_time")
# gpu_time_df <- as.data.frame(tlist,stringsAsFactors=T)

maxrange <- roundUpNice(max(total_time_df$total_time/1000))

# Plot Repeat measures for CPU resu lts as boxplot display of total times
library(rbokeh) # title="Singularity, Singulatity+HDF, R native CRAN, R + eigen_use_blas",
fig <- figure( ylab = "Total Time (s)", width = 600, legend_location = "top_right") %>%
  ly_boxplot(ncpu, total_time/1000,  data = total_time_df , color = "blue", legend="singularity") %>%
  ly_points(ncpu, average_time/1000, data = ave_time_df, hover=list(ngpu,ncpu,average_time/1000), color = "blue") %>% 
  y_range(c(0,maxrange ))                                                                                     # legend="singularity"


fig <- fig %>% 
  ly_boxplot(ncpu, total_time/1000,  data = total_time_df , color = "red", legend="singularity_hdf") %>%
  ly_points(ncpu, average_time/1000, data = ave_time_df, hover=list(ngpu,ncpu,average_time/1000), color = "red") # legend="singularity & HDF"


fig <- fig %>% 
  ly_boxplot(ncpu, total_time/1000,  data = total_time_df , color = "green", legend="R native + eigen_use_blas") %>%
  ly_points(ncpu, average_time/1000, data = ave_time_df, hover=list(ngpu,ncpu,average_time/1000), color = "green") #  legend="R & eigen_use_blas & hdf"


fig <- fig %>% 
  ly_boxplot(ncpu, total_time/1000,  data = total_time_df , color = "orange",  legend="R native CRAN") %>%
  ly_points(ncpu, average_time/1000, data = ave_time_df, hover=list(ngpu,ncpu,average_time/1000), color = "orange") # legend="R & CRAN equiv"


# to view the plot use this:
fig


# Add the GPU timing data: ncps_gpu_1
fig <- fig %>%  ly_points(x=ncps_gpu_1, y=total_time_gpu_1/1000, hover = list(total_time_gpu_1)) 

  ly_points(ncpu, average_time/1000, data = gpu_time_df, hover = list(total_time_gpu_1/1000, ngpu))
  
  
get_total_times_for_repeats <- function(df_rep_ss)
{
  df_fact <- NULL
  # df_fact <- rep('singularity_s',nrow(df_rep_ss))
  # df_rep_ss <- add_factor_col(df_rep_ss,df_fact)
  
  df_fact <- as.factor(df_rep_ss$run_id)  # distingush items by SLURM run so we can sum the total time for each run and then plot by numcpus
  
  lev_sid <- levels(df_fact)
  #num_sid_levels <- length(lev_sid)
  
  # initialised results vectors
  total_t_vect   <- vector("numeric",  length(lev_sid))
  ncpu_vect      <- vector("numeric", length(lev_sid))
  ngpu_vect      <- vector("numeric", length(lev_sid))
  sid_group_vect <- vector("numeric",  length(lev_sid))
  factlev        <- vector('character',length(lev_sid))
  
  fact_itter <- 1
  
  for (fact in lev_sid) {
    
    vect_ref <-  fact_itter
    sub_df <- subset(df_rep_ss, df_fact==fact, c(function.,ngpu,ncpu,time_ms))
    ncpu_vect[vect_ref]    <- unique(sub_df$ncpu)
    ngpu_vect[vect_ref]    <- unique(sub_df$ngpu)
    total_t_vect[vect_ref] <- sum((sub_df)$time_ms)
    factlev[vect_ref] <- fact
    
    
    fact_itter <- fact_itter + 1 ;
  }
  
  # Convert vectors to a list, add names and convert list to df
  tlist <- list(ngpu_vect,ncpu_vect,total_t_vect,factlev)
  names(tlist) <- c("ngpu","ncpu","total_time","system")
  total_time_df <- as.data.frame(tlist,stringsAsFactors=T)
  # str(ave_time_df$ncpu)
}

# this function requires the output from get_total_times_for_repeats() to 
# compute the total_time averages
get_average_times_for_repeats <- function(total_time_df)
{
  ## compute the average value to be used for hover overlay
  num_cpu_vals <- length(unique(total_time_df$ncpu))
  ave_by_cpu   <- vector('numeric',num_cpu_vals)
  cpu_by_cpu   <- vector('numeric',num_cpu_vals)
  gpu_by_gpu   <- vector('numeric',num_cpu_vals)
  cpu_order <- order(as.numeric(unique(total_time_df$ncpu))) 
  gpu_num <- as.numeric(unique(total_time_df$ngpu))
  itter <- 2
  # str(cpunum)
  for (itter in 1:num_cpu_vals) {
    cpunum <- unique(as.numeric(total_time_df$ncpu))[cpu_order[itter]]
   # gpunum <- unique(as.numeric(total_time_df$ngpu))[gpu_order[itter]]
    
    #message(cpunum)
    ave_by_cpu[itter]  <- ave(subset(total_time_df, ncpu==cpunum, c(total_time))$total_time)[1]
    cpu_by_cpu[itter] <- as.numeric(cpunum)
    gpu_by_gpu[itter] <- gpu_num
  }
 tlist <- list(as.character(gpu_by_gpu),as.character(cpu_by_cpu),ave_by_cpu)
 names(tlist) <- c("ngpu","ncpu","average_time")
  #tlist <- list(as.character(cpu_by_cpu),ave_by_cpu)
  # names(tlist) <- c(ncpu","average_time")
  ave_time_df <- as.data.frame(tlist,stringsAsFactors=T)
}


  

####################



#   ly_bar( x= as.factor(df_sub_calc_extBIC$ncpu), y= df_sub_calc_extBIC$time_ms,
#            position = "fill", width = 2) 
