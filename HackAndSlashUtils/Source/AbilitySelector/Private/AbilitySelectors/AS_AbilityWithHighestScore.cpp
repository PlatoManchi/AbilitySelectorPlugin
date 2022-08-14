#include "AbilitySelectors/AS_AbilityWithHighestScore.h"
#include "AbilityFilter.h"

TArray<FAbilitySelectData> UAS_AbilityWithHighestScore::TryGetAbilities_Implementation(UAbilityFilterData* ability_filter_data, const TArray<FAbilitySelectData>& abilities_list)
{
	check(ability_filter_data != nullptr);
	
	TArray<FAbilitySelectData> results;

	TArray<AbilityToScore> possible_ability_score;
	int max_score = 0;

	for (const FAbilitySelectData& data : abilities_list)
	{
		bool did_pass_all_filters = true;
		int score = 0;

		for (TObjectPtr<const UAbilityFilter> filter : data.m_ability_filters)
		{
			check(filter != nullptr);
			bool did_pass_filter = filter->CanPassFilter(ability_filter_data);

			// scoring abilities based on how many filters they pass
			if (did_pass_filter)
			{
				score += filter->GetPassingScore();
			}

			did_pass_all_filters = did_pass_all_filters && did_pass_filter;

			// Don't evulate filters any further if one filter fails
			if (!did_pass_all_filters) break;
		}

		// if all filters in an ability is passed.
		if (did_pass_all_filters)
		{
			if (max_score < score)
			{
				max_score = score;
			}

			AbilityToScore ability_score{ data , score };
			possible_ability_score.Add(ability_score);
		}
	}

	// Filter all abilities with highest score
	possible_ability_score = possible_ability_score.FilterByPredicate([max_score](const AbilityToScore& param) { return param.m_score == max_score; });

	for (AbilityToScore& ability : possible_ability_score)
	{
		results.Add(ability.m_ability_select_data);
	}

	return results;
}

