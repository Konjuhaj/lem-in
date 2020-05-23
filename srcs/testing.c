/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:15:44 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/05/10 21:01:19 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void moveLeft(int *nums, int size)
{
    int i;

    i = 0;
    while (++i < size)
        nums[i - 1] = nums[i];
	nums[i] = 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    int i;
    int j;
    int ret;
    int temp;

    i = -1;
    ret = numsSize;
    while (++i < numsSize)
    {
        temp = nums[i];
		j = i;
        while (++j < numsSize)
        {
            if (temp == nums[j])
            {
                moveLeft(nums + j, numsSize - j);
                ret--;
            }
			printf("%d\n", j);
        }
    }
    return (ret);
}

int main(void)
{
	int nums[] = {1, 1, 2};
	printf("%d",removeDuplicates(nums, 3));
	return (0);
}
