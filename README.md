# Statistical-Analysis
This is a program that computes descriptive statistics and performs a two-sample analysis on a given data set.

Two-Sample Analysis
    We may also want to compare two different samples via statistical analysis and make inferences about the underlying populations they represent. We might survey different populations entirely separately, or partition a data set into subgroups based on specific criteria. For example, we might filter responses to the HCMST survey based on whether people met their partner online or not, yielding two samples representing distinct populations. Then, we could compute the mean age for each sample, as well as the difference between those means, finding that to be approximately 7.6 years older for the sample of people who did not meet their partner online.
However, inferences drawn from samples must be qualified in a way that accounts for the probability the observed difference is due to random chance (i.e. the uncertainty introduced by sampling). It would not be responsible to simply report the 7.6 point estimate as the difference in means among the underlying populations.

Bootstrap Confidence Intervals
    Instead of reporting a single estimate based on a sample, we instead set up a procedure for computing a range of possible values (i.e. lower and upper bounds) defining a confidence interval at a particular confidence level of X%. The interpretation is as follows: If we collected many samples (i.e. ran the survey many times), X% of the time the computed confidence interval would contain the true underlying value among the population.
Of course, it’s not practical to actually conduct the survey many times, so we instead use an approach called bootstrap resampling. The essential idea is that we simulate taking several samples by instead re-sampling (with replacement) from one original sample.
For example, assume the original sample contained individuals [A, B, C, D]. Bootstrap resamples of this could be [A, C, C, D] or [A, A, A, B]. Each approximates a plausible sample we could have drawn from the underlying population (i.e. a resample of [A, A, A, B] approximates a sample that happened to have more people like A and less like C or D).

We can compute the statistic of interest (e.g. the difference in means) for many resamples to obtain an approximate sampling distribution from which we can compute a confidence interval.
